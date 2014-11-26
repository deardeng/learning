#include "Deposit.h"

#include "../../Public/Logging.h"
#include "../../Public/JUtil.h"
#include "../../Public/JinStream.h"
#include "../../Public/JOutStream.h"
using namespace PUBLIC;
using namespace CMD;


void Deposit::Execute(BankSession& session){
	JOutStream jos;
	uint16 cmd = CMD_DEPOSIT;
	jos << cmd;
	size_t lengthPos = jos.Length();
	jos.Skip(2);
	string account_id = session.GetAttribute("account_id");
	jos.WriteBytes(account_id.c_str(), 6);

	string money = session.GetAttribute("money");
	jos << money;
	size_t tailPos = jos.Length();
	jos.Reposition(lengthPos);
	jos << (uint16)(tailPos + 8 -sizeof(RequestHead));

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
	session.Recv();
	JInStream jis((const char*)session.GetResponsePack(),
		session.GetResponsePack()->head.len + sizeof(ResponseHead));

	jis.Skip(4);
	uint16 cnt;
	uint16 seq;
	int16 error_code;
	jis >> cnt >> seq >> error_code;

	char error_msg[31];
	jis.ReadBytes(error_msg, 30);

	session.SetErrorCode(error_code);
	session.SetErrorMsg(error_msg);
	
	if(0 == error_code)
	{
		string name;
		jis >> name;
		jis >> money;
		string trans_date;
		jis >> trans_date;

		//char trans_date[20] = {0};
		//jis.ReadBytes(trans_date, 19);
		session.SetResponse("name", name);
		session.SetResponse("balance", money);
		session.SetResponse("trans_date", trans_date);
	}
}
