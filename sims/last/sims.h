#ifndef _SIMS_H_
#define _SIMS_H_
#include <iostream>
using namespace std;
#include <string>
#include "list.h"

#define USR_NAME_LEN 20
#define USR_PWD_LEN 100

typedef int USR_ROLE;
typedef string USR_ACCOUNT_NUM;
typedef int USR_INFOR_NUM;
typedef int SEARCH_ID;

typedef struct usr_account_tag{
    char usr_name[USR_NAME_LEN];//登陆账户用户名
    char usr_pwd[USR_PWD_LEN];//密码
    USR_ROLE usr_role;//账户角色：    ture：管理员 false：普通账户
}USR_ACCOUNT,*pUSR_ACCOUNT;


typedef struct usr_infor_tag{
    int usr_id;//学生id
    char usr_name[USR_NAME_LEN];//学生姓名
    int usr_course_id;//课程id
    double usr_course_score;//课程分数
}USR_INFOR,*pUSR_INFOR;
void Usr_Account_Show(const List<pUSR_ACCOUNT> &who);
void Usr_Infor_Show(const List<pUSR_INFOR> &who);
void call_search_menu(List<pUSR_INFOR>& student,USR_ROLE role);
int system_init(const char* config_file_name,List<pUSR_ACCOUNT>& user,List<pUSR_INFOR>& student,USR_ACCOUNT_NUM &usr_account_num,USR_INFOR_NUM &usr_infor_num);
USR_ROLE role_confirm(List<pUSR_ACCOUNT>& user,const string& username,USR_ACCOUNT_NUM& usr_account_num);
int show_system_menu(USR_ROLE role,int &select_system_num);
int show_search_menu(USR_ROLE role,int &select_search_num);
void search_usr_infor_by_id(List<pUSR_INFOR>& student,SEARCH_ID& search_id);
void search_usr_infor_by_name(List<pUSR_INFOR>& student,string& search_name);
pUSR_INFOR add_usr_infor(List<pUSR_INFOR>& student,USR_INFOR_NUM &usr_infor_num);
pUSR_INFOR update_usr_infor(List<pUSR_INFOR>& student,SEARCH_ID search_id);
pUSR_INFOR delete_usr_infor(List<pUSR_INFOR>& student,SEARCH_ID search_id);
void search_usr_account(List<pUSR_ACCOUNT>& user,string& search_name);
pUSR_ACCOUNT add_usr_account(List<pUSR_ACCOUNT>& user);
pUSR_ACCOUNT update_usr_account(List<pUSR_ACCOUNT> &user,string& search_name);
pUSR_ACCOUNT delete_usr_account(List<pUSR_ACCOUNT> &user,string& search_name);
void save_data_to_file(const char* config_file_name,List<pUSR_ACCOUNT> &user,List<pUSR_INFOR> &student);

#endif
