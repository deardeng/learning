#include <Windows.h>
#include <mysql.h>
#include <stdio.h>

int main(){
	// 初始化一个连接句柄MYSQL
	MYSQL* mysql;
	mysql = mysql_init(NULL);
	if(mysql == NULL){
		printf("error: %s\n",mysql_error(mysql));
		return 1;
	}

	my_bool reconnect = true;
	mysql_options(mysql,MYSQL_OPT_RECONNECT,&reconnect);
	mysql_options(mysql,MYSQL_SET_CHARSET_NAME,"gbk");


	//mysql_real_connect(MYSQL *mysql,
	//	const char *host, 
	//	const char *user, 
	//	const char *passwd, 
	//	const char *db, 
	//	unsigned int port, 
	//	const char *unix_socket, 
	//	unsigned long clientflag)


	if(!mysql_real_connect(mysql,"localhost","root","123456","scott",
		0,NULL,0)){
			printf("error: %s\n",mysql_error(mysql));
			return 1;
	}

	int result;
	// 没有返回结果集的操作
	result = mysql_query(mysql,"INSERT into emp values(8888,'YYYY','CLERK',7782,'1982-01-23',1300,null,30)");
	if(result != 0){
		printf("error: %s\n",mysql_error(mysql));
		return 1;
	}

	printf("%llu 行受影响\n",mysql_affected_rows(mysql));

	result = mysql_query(mysql,"SELECT * from emp where deptno = 30");
	if(result != 0){
		printf("error: %s\n",mysql_error(mysql));
		return 1;
	}

	MYSQL_ROW mysql_row;
	MYSQL_RES* mysql_res;
	MYSQL_FIELD* mysql_field;
	unsigned int cols;
	mysql_res = mysql_store_result(mysql);
	cols = mysql_num_fields(mysql_res);
	if(mysql_res){
		printf("返回%llu行\n",mysql_num_rows(mysql_res));
		while((mysql_field = mysql_fetch_field(mysql_res))){
			printf("%s\t",mysql_field->name);
		}
		printf("\n");
		while((mysql_row = mysql_fetch_row(mysql_res))){
			for(unsigned int i = 0;i < cols; ++i){
				printf("%s\t",mysql_row[i]?mysql_row[i]:"NULL");
			}
			printf("\n");
		}

		mysql_free_result(mysql_res);
	}


	mysql_close(mysql);
	return 0;
}

//libmysql.lib 这仅仅只是包含libmysql.dll的一些符号信息，并不包含实际的实现代码
//libmysql.dll 包含实际的实现代码

//静态链接
//动态链接 LoadLibrary GetProcAddress

