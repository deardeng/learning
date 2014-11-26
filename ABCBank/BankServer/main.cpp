#include "Server.h"
//#include "../Public/MD5.h"
//#include <stdio.h>
#include <iostream>
#include "DAL/MysqlDB.h"
#include "../Public/Exception.h"
#include "../Public/Logging.h"

using namespace std;
using namespace PUBLIC;
using namespace DAL;
int main(void){

	//MysqlDB db;
	//try
	//{
	//	db.Open("localhost", "root", "123456", "scott", 0);
	//	unsigned long long ret = db.ExecSQL(
	//		"insert into emp values(321, 'xxx', 'CLERK', 7782, '1989-05-19', 2300, null, 40)");
	//	cout << ret << "ÐÐÊÜÓ°Ïì" << endl;

	//	MysqlRecordset rs = db.QuerySQL("select * from emp where deptno=30;");
	//	cout << "empno ename" << endl;
	//	for(unsigned int i=0; i<rs.GetRows(); ++i)
	//	{
	//		cout << rs.GetItem(i, "empno") << " " << rs.GetItem(i, "ename") << endl;
	//	}
	//}
	//catch(Exception& e)
	//{
	//	LOG_INFO << e.what();
	//	db.Close();
	//}

	//db.Close();


	//MD5 md5;
	//unsigned char hash[16];
	//md5.MD5Make(hash, (unsigned char const *)"deardeng", 8);
	//int i;
	//for(i=0; i<16; ++i){
	//	printf("%0X", hash[i]);
	//}
	//printf("\n");
	return Singleton<Server>::Instance().Start();
}