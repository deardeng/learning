#include "Deposit.h"

#include "../../Public/Logging.h"
#include "../../Public/JUtil.h"
#include "../DAL/BankService.h"
#include "../../Public/JinStream.h"
#include "../../Public/JOutStream.h"

using namespace DAL;
using namespace PUBLIC;
using namespace CMD;

void Deposit::Execute(BankSession& session){
	JInStream jis(session.GetRequestPack()->buf, session.GetRequestPack()->head.len);
	uint16 cmd = session.GetCmd();

	char account_id[7] = {0};
	jis.ReadBytes(account_id, 6);

	string money;
	jis >> money;

	BankService dao;
	int16 error_code = 0;
	char error_msg[31] = {0};

	Account acc;
	acc.account_id = Convert::StringToInt(account_id);
	acc.balance = Convert::StringToDouble(money);

	int ret = dao.Deposit(acc);
	if(0 == ret)
	{
		LOG_INFO << "存款成功";
	}
	else if(2 == ret)
	{
		error_code = 2;
		strcpy_s(error_msg, "账户不存在");
		LOG_INFO << error_msg;
	}
	else if(-1 == ret)
	{
		error_code = -1;
		strcpy_s(error_msg, "数据库错误");
		LOG_INFO << error_msg;
	}

	JOutStream jos;
	jos << cmd;
	size_t lengthPos = jos.Length();
	jos.Skip(2);
	uint16 cnt = 0;
	uint16 seq = 0;
	jos << cnt << seq << error_code;
	jos.WriteBytes(error_msg, 30);

	if(error_code == 0)
	{
		string balance = Convert::DoubleToString(acc.balance);
		jos << acc.name << balance;
		//jos.WriteBytes(acc.op_date.c_str(), 19);
		jos << acc.op_date;
	}
	size_t tailPos = jos.Length();
	jos.Reposition(lengthPos);
	jos << (uint16)(tailPos + 8 - sizeof(ResponseHead));

	jos.Reposition(tailPos);
	unsigned char hash[16];
	MD5 md5;
	md5.MD5Make(hash, (unsigned char const*)jos.Data(), jos.Length());
	for(int i=0; i<8; ++i)
	{
		hash[i] = hash[i] ^ hash[i+8];
		hash[i] = hash[i] ^ ((cmd >> (i%2)) & 0xff);
	}
	jos.WriteBytes(hash, 8);
	session.Send(jos.Data(), jos.Length());
}
