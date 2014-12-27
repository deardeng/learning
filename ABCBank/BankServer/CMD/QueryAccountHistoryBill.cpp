#include "QueryAccountHistoryBill.h"

#include "../../Public/Logging.h"
#include "../../Public/JUtil.h"
#include "../DAL/BankService.h"
#include "../../Public/JinStream.h"
#include "../../Public/JOutStream.h"
using namespace DAL;
using namespace PUBLIC;
using namespace CMD;

void QueryAccountHistoryBill::Execute(BankSession& session)
{
	JInStream jis(session.GetRequestPack()->buf, session.GetRequestPack()->head.len);
	uint16 cmd = session.GetCmd();

	uint32 page;
	jis >> page;

	char account_id[7] = {0};
	jis.ReadBytes(account_id, 6);

	char begin_date[11] = {0};
	jis.ReadBytes(begin_date, 10);

	char end_date[11] = {0};
	jis.ReadBytes(end_date, 10);

	BankService dao;
	int16 error_code = 0;
	char error_msg[31] = {0};

	list<TransDetail> details;
	int ret = dao.QueryAccountHistoryBill(details, page, account_id, begin_date, end_date);
	if(ret == 6)
	{
		error_code = 6;
		strcpy_s(error_msg, "没有找到数据");
		LOG_INFO << error_msg;
	}
	else if(ret == -1)
	{
		error_code = -1;
		strcpy_s(error_msg, "数据库错误");
		LOG_INFO << error_msg;
	}
	if(error_code == 0)
	{
		LOG_INFO << "查询成功";
		uint16 cnt = static_cast<uint16>(details.size());
		uint16 seq = 0;
		list<TransDetail>::const_iterator it;
		for(it=details.begin(); it!=details.end(); ++it)
		{
			JOutStream jos;
			jos << cmd;
			size_t lengthPos = jos.Length();
			jos.Skip(2);
			jos << cnt << seq << error_code;
			seq++;
			jos.WriteBytes(error_msg, 30);

			jos.WriteBytes(it->trans_date.c_str(), 19);
			jos.WriteBytes(it->account_id.c_str(), 6);
			jos.WriteBytes(it->other_account_id.c_str(), 6);
			string money = Convert::DoubleToString(it->money);
			jos << money;
			jos << it->abstract_name;
			string balance = Convert::DoubleToString(it->balance);
			jos << balance;
			jos << it->total;

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
	}
	else
	{
		JOutStream jos;

		uint16 cnt = 0;
		uint16 seq = 0;
		jos << cmd;
		size_t lengthPos = jos.Length();
		jos.Skip(2);
		jos << cnt << seq << error_code;
		jos.WriteBytes(error_msg, 30);

		size_t tailPos = jos.Length();
		jos.Reposition(lengthPos);
		jos << (uint16)(tailPos + 8 -sizeof(ResponseHead));

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
}
