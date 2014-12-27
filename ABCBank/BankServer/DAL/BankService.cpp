#include "BankService.h"
#include "../Server.h"
#include "../../Public/Logging.h"
#include "../../Public/Exception.h"
#include "../../Public/JUtil.h"
#include "MysqlDB.h"
#include <sstream>
using namespace std;
using namespace DAL;
using namespace PUBLIC;

int BankService::UserLogin(const string& user, const string& pass){
	//if(user != "admin" || pass != "123456")
	//	return 1;
	
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();

	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());
		stringstream ss;
		ss << "select teller_name from teller where teller_name='" <<
			user << "' and teller_pass='" << pass << "';";
		MysqlRecordset rs;
		rs = db.QuerySQL(ss.str().c_str());
		if(rs.GetRows() < 1)
			return 1;
	}
	catch(Exception& e)
	{
		LOG_INFO << e.what();
		return -1;
	}

	return 0;

}

int BankService::OpenAccount(Account& account){
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();

	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());
		db.StartTransaction();

		stringstream ss;
		ss << "insert into bank_account values(null, '" << account.name << "', '"
			<< account.pass << "', '" << account.id << "', " << 
			setprecision(2) << setiosflags(ios::fixed) << account.balance << ", now(), " <<
			0 << ");";
		unsigned long long ret = db.ExecSQL(ss.str().c_str());
		
		ss.clear();
		ss.str("");
		account.account_id = static_cast<int>(db.GetInsertId());
		ss << "insert into trans values(null, " << account.account_id << ", null, " << 1
			<< ", " << setprecision(2) << setiosflags(ios::fixed) << account.balance << ", " <<
			setprecision(2) << setiosflags(ios::fixed) << account.balance << ", now());";

		ret = db.ExecSQL(ss.str().c_str());
		db.Commit();
		ss.clear();
		ss.str("");
		ss << "select open_date from bank_account where account_id='" <<
			account.account_id << "';";
		MysqlRecordset rs = db.QuerySQL(ss.str().c_str());
		account.op_date = rs.GetItem(0, "open_date");
	}
	catch(Exception& e)
	{
		LOG_INFO << e.what();
		db.Rollback();
		return -1;
	}
	return 0;
}

int BankService::CloseAccount(Account& account, double& interest)
{
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();

	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());

		db.StartTransaction();
		stringstream ss;
		ss << "select balance from bank_account where account_id=" << account.account_id << " and flag=0;";
		MysqlRecordset rs = db.QuerySQL(ss.str().c_str());
		if(rs.GetRows() < 1)
			return 2;
		//LOG_INFO << ss.str();
		ss.clear();
		ss.str("");
		ss << "select balance from bank_account where account_id="
			<< account.account_id << " and pass=" << account.pass << " for update;";
		//LOG_INFO << ss.str();
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		if(rs.GetRows() < 1)
			return 3;

		account.balance = Convert::StringToDouble(rs.GetItem(0, "balance"));

		ss.clear();
		ss.str("");
		ss << "select sum(yy.days*yy.balance)*" << server.GetInteretRate() << "/360 interest from(" <<
			"select trans_id, balance, trans_date, next_date, " <<
			"datediff(if(next_date, next_date, now()), trans_date) days from (" <<
			"select trans_id, balance, trans_date, (" <<
			"select min(trans_date) from (" <<
			"select * from trans where trans_id in (" <<
			"select max(trans_id) from trans where account_id=" << account.account_id <<
			" group by date_format(trans_date, '%Y-%m-%d')))" <<
			" b where b.trans_date > a.trans_date) next_date from (" <<
			"select * from trans where trans_id in " <<
			"(select max(trans_id) from trans where account_id =" << account.account_id <<
			" group by date_format(trans_date, '%Y-%m-%d'))) a) xx) yy";

		//LOG_INFO << ss.str();
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		interest = Convert::StringToDouble(rs.GetItem(0, "interest"));

		ss.clear();
		ss.str("");
		ss << "update bank_account set flag=1 where account_id=" <<
			account.account_id << ";";
		//LOG_INFO << ss.str();
		db.ExecSQL(ss.str().c_str());

		db.Commit();

		ss.clear();
		ss.str("");
		ss << "select name, now() close_date from bank_account " <<
			"where account_id=" << account.account_id << ";";
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		account.name = rs.GetItem(0, "name");
		account.op_date = rs.GetItem(0, "close_date");
	}
	catch(Exception& e)
	{
		LOG_INFO << e.what();
		return -1;
	}
	return 0;
}

int BankService::ChangePassword(Account& account, const string& newPass){
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();

	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());
		stringstream ss;
		ss << "select balance from bank_account where account_id=" <<
			account.account_id <<
			" and flag=0;";
		MysqlRecordset rs = db.QuerySQL(ss.str().c_str());
		if(rs.GetRows() < 1)
			return 2;
		ss.clear();
		ss.str("");
		ss << "select balance from bank_account where account_id=" <<
			account.account_id << " and pass=" << account.pass << ";";
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		if(rs.GetRows() < 1)
			return 3;
		ss.clear();
		ss.str("");
		ss << "update bank_account set pass='" <<
			newPass << "' " <<
			"where account_id=" <<
			account.account_id << ";";
		db.ExecSQL(ss.str().c_str());
	}
	catch(Exception& e)
	{
		LOG_INFO << e.what();
		return -1;
	}
	return 0;
}

int BankService::Deposit(Account& account){
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();
	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());
		db.StartTransaction();

		stringstream ss;
		ss << "select balance from bank_account where account_id=" << 
			account.account_id << 
			" and flag=0 for update;";

		MysqlRecordset rs = db.QuerySQL(ss.str().c_str());
		if(rs.GetRows() < 1)
			return 2;

		double balance = Convert::StringToDouble(rs.GetItem(0, "balance"));
		ss.clear();
		ss.str("");
		ss << "update bank_account set balance=balance+" <<
			setprecision(2) << setiosflags(ios::fixed) << account.balance << " where account_id=" <<
			account.account_id << ";";
		unsigned long long ret = db.ExecSQL(ss.str().c_str());
		
		ss.clear();
		ss.str("");
		ss << "insert into trans values(null, " <<
			account.account_id << ", null, " << 2 << ", "
			<< setprecision(2) << setiosflags(ios::fixed) << account.balance << ", " 
			<< setprecision(2) << setiosflags(ios::fixed) << balance+account.balance << ", now());";
		ret = db.ExecSQL(ss.str().c_str());

		int trans_id = static_cast<int>(db.GetInsertId());
		db.Commit();
		ss.clear();
		ss.str("");
		ss << "select a.name, b.trans_date " <<
			"from bank_account a, " <<
			"(select account_id, trans_date from trans where trans_id=" <<
			trans_id << ") b " << "where a.account_id = b.account_id;";
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		account.name = rs.GetItem(0, "name");
		account.op_date = rs.GetItem(0, "trans_date");
		account.balance += balance;
	}
	catch(Exception& e)
	{
		db.Rollback();
		LOG_INFO << e.what();
		return -1;
	}
	return 0;
}

int BankService::WithDraw(Account& account){
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();
	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());
		db.StartTransaction();

		stringstream ss;
		ss << "select balance from bank_account where account_id=" <<
			account.account_id << 
			" and flag=0;";
		MysqlRecordset rs = db.QuerySQL(ss.str().c_str());
		if(rs.GetRows() < 1)
			return 2;
		ss.clear();
		ss.str("");
		ss << "select balance from bank_account where account_id=" <<
			account.account_id << " and pass=" << account.pass << " for update;";
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		if(rs.GetRows() < 1)
			return 3;

		double balance = Convert::StringToDouble(rs.GetItem(0, "balance"));
		if(account.balance > balance)
			return 4;

		ss.clear();
		ss.str("");
		ss << "update bank_account set balance=balance-" <<
			setprecision(2) << setiosflags(ios::fixed) << account.balance << " where account_id=" <<
			account.account_id << ";";
		unsigned long long ret = db.ExecSQL(ss.str().c_str());
	
		ss.clear();
		ss.str("");
		ss << "insert into trans values(null, " <<
			account.account_id << ", null, " <<
			3 << ", " <<
			setprecision(2) << setiosflags(ios::fixed) << account.balance << ", " <<
			setprecision(2) << setiosflags(ios::fixed) << balance-account.balance <<
			", now());";
		ret = db.ExecSQL(ss.str().c_str());
		int trans_id = static_cast<int>(db.GetInsertId());
		db.Commit();
		ss.clear();
		ss.str("");
		ss << "select a.name, b.trans_date " << 
			"from bank_account a, " << 
			"(select account_id, trans_date from trans where trans_id=" << 
			trans_id << ") b " <<
			"where a.account_id = b.account_id;";
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		account.name = rs.GetItem(0, "name");
		account.op_date = rs.GetItem(0, "trans_date");
		account.balance = balance - account.balance;

	}
	catch(Exception& e)
	{
		LOG_INFO << e.what();
		db.Rollback();
		return -1;
	}
	return 0;
}

int BankService::Transfer(Account& account, const string& otherAccountId){
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();

	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());

		db.StartTransaction();
		stringstream ss;

		ss << "select balance from bank_account where account_id=" << 
			account.account_id <<
			" and flag=0;";
		MysqlRecordset rs = db.QuerySQL(ss.str().c_str());
		if(rs.GetRows() < 1)
			return 2;
		ss.clear();
		ss.str("");
		ss << "select balance from bank_account where account_id=" <<
			account.account_id << " and pass=" << account.pass << " for update;";
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		if(rs.GetRows() < 1)
			return 3;

		double balance = Convert::StringToDouble(rs.GetItem(0, "balance"));
		if(account.balance > balance)
			return 4;
		ss.clear();
		ss.str("");
		ss << "select balance from bank_account where account_id=" <<
			otherAccountId << 
			" and flag=0 for update;";
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		if(rs.GetRows() < 1)
			return 5;

		double balance2 = Convert::StringToDouble(rs.GetItem(0, "balance"));
		
		ss.clear();
		ss.str("");
		ss << "update bank_account set balance=balance-" <<
			setprecision(2) << setiosflags(ios::fixed) << account.balance << " where account_id=" <<
			account.account_id << ";";
		unsigned long long ret = db.ExecSQL(ss.str().c_str());
		ss.clear();
		ss.str("");
		ss << "update bank_account set balance=balance+" <<
			setprecision(2) << setiosflags(ios::fixed) << account.balance << " where account_id=" <<
			otherAccountId << ";";
		ret = db.ExecSQL(ss.str().c_str());

		ss.clear();
		ss.str("");
		ss << otherAccountId;
		int other_account_id;
		ss >> other_account_id;

		ss.clear();
		ss.str("");
		ss << "insert into trans values(null, " <<
			account.account_id << ", " <<
			other_account_id << 
			", " << 5 << ", " <<
			setprecision(2) << setiosflags(ios::fixed) << account.balance << ", " <<
			setprecision(2) << setiosflags(ios::fixed) << balance-account.balance <<
			", now());";

		ret = db.ExecSQL(ss.str().c_str());

		int trans_id = static_cast<int>(db.GetInsertId());
		ss.clear();
		ss.str("");
		ss << "select a.name, b.trans_date " << 
			"from bank_account a, " <<
			"(select account_id, trans_date from trans where trans_id=" << 
			trans_id << ") b " <<
			"where a.account_id=b.account_id;";
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());

		ss.clear();
		ss.str("");
		ss << "insert into trans values(null ," <<
			other_account_id << ", " <<
			account.account_id << ", " << 4 << ", " <<
			setprecision(2) << setiosflags(ios::fixed) << account.balance << ", " <<
			setprecision(2) << setiosflags(ios::fixed) << balance2 + account.balance <<
			", now());";

		ret = db.ExecSQL(ss.str().c_str());
		db.Commit();

		account.balance = balance - account.balance;
		account.name = rs.GetItem(0, "name");
		account.op_date = rs.GetItem(0, "trans_date");
	}
	catch(Exception& e)
	{
		db.Rollback();
		LOG_INFO << e.what();
		return -1;
	}
	return 0;
}

int BankService::BalanceInquiry(Account& account){
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();

	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());
		stringstream ss;
		ss << "select balance from bank_account where account_id=" <<
			account.account_id <<
			" and flag=0;";
		MysqlRecordset rs = db.QuerySQL(ss.str().c_str());
		if(rs.GetRows() < 1)
			return 2;
		ss.clear();
		ss.str("");
		ss << "select balance from bank_account where account_id=" <<
			account.account_id << " and pass=" << account.pass << ";";
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		if(rs.GetRows() < 1)
			return 3;
		account.balance = Convert::StringToDouble(rs.GetItem(0, "balance"));
		ss.clear();
		ss.str("");
		ss << "select name, now() query_date from bank_account " << 
			"where account_id=" <<
			account.account_id << ";";
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		account.name = rs.GetItem(0, "name");
		account.op_date = rs.GetItem(0, "query_date");
	}
	catch(Exception& e)
	{
		LOG_INFO << e.what();
		return -1;
	}
	return 0;
}

int BankService::QueryDayBill(list<TransDetail>& result, int page, const string& date){
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();

	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());
		stringstream ss;
		ss << "select count(*) as total from " << "(select * from trans where date_format(trans_date, '%Y-%m-%d')='"
			<< date << "') as a, abstract b where a.abstract_id = b.abstract_id;";
		MysqlRecordset rs = db.QuerySQL(ss.str().c_str());
		int total = Convert::StringToDouble(rs.GetItem(0, "total"));

		ss.clear();
		ss.str("");
		ss << "select a.account_id, a.other_account_id, b.name, a.money, a.balance, a.trans_date from " <<
			"(select * from trans where date_format(trans_date, '%Y-%m-%d')='" <<
			date <<
			"') a, abstract b where a.abstract_id = b.abstract_id order by a.trans_date limit " << 
			page*15 << ", 15;";
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		if(rs.GetRows() < 1)
			return 6;

		for(unsigned int i=0; i<rs.GetRows(); ++i)
		{
			TransDetail td;
			td.account_id = rs.GetItem(i, "account_id");
			td.other_account_id = rs.GetItem(i, "other_account_id");
			td.abstract_name = rs.GetItem(i, "name");

			td.money = Convert::StringToDouble(rs.GetItem(i, "money"));
			td.balance = Convert::StringToDouble(rs.GetItem(i, "balance"));

			td.trans_date = rs.GetItem(i, "trans_date");
			td.total = total;

			result.push_back(td);
		}
		
	}
	catch(Exception& e)
	{
		LOG_INFO << e.what();
		return -1;
	}
	return 0;
}

int BankService::QueryHistoryBill(list<TransDetail>& result, int page, const string& begin, const string& end){
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();
	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());

		stringstream ss;
		ss << "select count(*) as total from " << 
			"(select * from trans where date_format(trans_date, '%Y-%m-%d') between '" << begin << "' and '" <<
			end << "') a, abstract b where a.abstract_id = b.abstract_id;";
		//LOG_INFO << ss.str();
		MysqlRecordset rs = db.QuerySQL(ss.str().c_str());

		int total = Convert::StringToInt(rs.GetItem(0, "total"));

		ss.clear();
		ss.str("");
		ss << "select a.account_id, a.other_account_id, b.name, a.money, a.balance, a.trans_date from " <<
			"(select * from trans where date_format(trans_date, '%Y-%m-%d') between '" <<
			begin << "' and '" << end << "') a, abstract b where a.abstract_id = b.abstract_id order by a.trans_date limit " <<
			page*15 << ", 15;";
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		if(rs.GetRows() < 1)
			return 6;

		for(unsigned int i=0; i<rs.GetRows(); ++i)
		{
			TransDetail td;
			td.account_id = rs.GetItem(i, "account_id");
			td.other_account_id = rs.GetItem(i, "other_account_id");
			td.abstract_name = rs.GetItem(i, "name");

			td.money = Convert::StringToDouble(rs.GetItem(i, "money"));
			td.balance = Convert::StringToDouble(rs.GetItem(i, "balance"));

			td.trans_date = rs.GetItem(i, "trans_date");
			td.total = total;

			result.push_back(td);
		}
	}
	catch(Exception& e)
	{
		LOG_INFO << e.what();
		return -1;
	}
	return 0;
}

int BankService::QueryAccountHistoryBill(list<TransDetail>& result, int page, const string& accountId, const string& begin, const string& end){
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();
	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());

		stringstream ss;
		ss<<"select count(*) as total from "<<	
		"(select * from trans where account_id=" << 
		accountId << " and date_format(trans_date, '%Y-%m-%d') between '" <<
		begin << "' and '" << end << " ') as a, abstract b where a.abstract_id = b.abstract_id;";

		//LOG_INFO << ss.str();
		MysqlRecordset rs = db.QuerySQL(ss.str().c_str());

		int total = Convert::StringToInt(rs.GetItem(0, "total"));

		ss.clear();
		ss.str("");
		ss << "select a.account_id, a.other_account_id, b.name, a.money, a.balance, a.trans_date from "
			<< "(select * from trans where account_id=" << accountId << " and date_format(trans_date, '%Y-%m-%d') between '" <<
			begin << "' and '" << end << "') a, abstract b where a.abstract_id = b.abstract_id order by a.trans_date limit " <<
			page*15 << ", 15;";

		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		if(rs.GetRows() < 1)
			return 6;

		for(unsigned int i=0; i<rs.GetRows(); ++i)
		{
			TransDetail td;
			td.account_id = rs.GetItem(i, "account_id");
			td.other_account_id = rs.GetItem(i, "other_account_id");
			td.abstract_name = rs.GetItem(i, "name");

			td.money = Convert::StringToDouble(rs.GetItem(i, "money"));
			td.balance = Convert::StringToDouble(rs.GetItem(i, "balance"));
			td.trans_date = rs.GetItem(i, "trans_date");
			td.total = total;

			result.push_back(td);
		}
	}
	catch(Exception& e)
	{
		LOG_INFO << e.what();
		return -1;
	}
	return 0;
}
