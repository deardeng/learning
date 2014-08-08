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
    //struct usr_account_tag *pNext_Usr_Account;//指向下一个账户节点
}USR_ACCOUNT,*pUSR_ACCOUNT;


typedef struct usr_infor_tag{
    int usr_id;//学生id
    char usr_name[USR_NAME_LEN];//学生姓名
    int usr_course_id;//课程id
    double usr_course_score;//课程分数
    //struct usr_infor_tag *pNext_Usr_Infor;//指向下一个学生节点
}USR_INFOR,*pUSR_INFOR;
void Usr_Account_Show(const List<pUSR_ACCOUNT> &who);
void Usr_Infor_Show(const List<pUSR_INFOR> &who);
void call_search_menu(List<pUSR_INFOR>& student,USR_ROLE role);
int system_init(const char* config_file_name,List<pUSR_ACCOUNT>& user,List<pUSR_INFOR>& student,USR_ACCOUNT_NUM &usr_account_num,USR_INFOR_NUM &usr_infor_num);
//void system_init(const char* config_file_name,pUSR_ACCOUNT *pUsr_Account,pUSR_INFOR *pUsr_Infor,USR_ACCOUNT_NUM *usr_account_num,USR_INFOR_NUM *usr_infor_num);
//系统初始化函数。初始化内存中的学生信息链表和用户信息链表
//USR_ROLE role_confirm(pUSR_ACCOUNT pUsr_Account,USR_ACCOUNT_NUM usr_account_num);
USR_ROLE role_confirm(List<pUSR_ACCOUNT>& user,const string& username,USR_ACCOUNT_NUM& usr_account_num);
//根据输入的用户名和密码检查是否合法并确认当前帐号权限（管理员或者普通用户）
//SYSTEM_MENU_TYPE show_system_menu(USR_ROLE role);
int show_system_menu(USR_ROLE role,int &select_system_num);
//显示系统菜单，返回当前用户所选择的菜单
//SYSTEM_MENU_TYPE show_search_menu(USR_ROLE role);
int show_search_menu(USR_ROLE role,int &select_search_num);
//当前用户选择查询功能时根据权限显示具有不同功能的查询功能的菜单
//void search_usr_infor_by_id(pUSR_INFOR pUsr_Infor_List,SEARCH_ID search_id);
void search_usr_infor_by_id(List<pUSR_INFOR>& student,SEARCH_ID& search_id);
//根据当前用户所输的学号查询相应的学生信息
//void search_usr_infor_by_name(pUSR_INFOR pUsr_Infor_List,string& search_name);
void search_usr_infor_by_name(List<pUSR_INFOR>& student,string& search_name);
//根据当前用户所输的姓名查询相应的学生信息
pUSR_INFOR add_usr_infor(List<pUSR_INFOR>& student,USR_INFOR_NUM &usr_infor_num);
//添加学生信息，返回指向插入学生的指针
//pUSR_INFOR update_usr_infor(pUSR_INFOR pUsr_Infor_List,SEARCH_ID search_id);
pUSR_INFOR update_usr_infor(List<pUSR_INFOR>& student,SEARCH_ID search_id);
//修改学生的信息，返回指向修改后的学生的信息的指针
//pUSR_INFOR delete_usr_infor(pUSR_INFOR *pUsr_Infor_List,USR_INFOR_NUM *usr_infor_num,SEARCH_ID search_id);
pUSR_INFOR delete_usr_infor(List<pUSR_INFOR>& student,SEARCH_ID search_id);
//删除学生的信息，返回所删除的学生的下一个学生的指针
//void search_usr_account(pUSR_ACCOUNT pUsr_Account_List,char *search_name);
void search_usr_account(List<pUSR_ACCOUNT>& user,string& search_name);
//根据当前帐号输入的帐号名查询相应的帐号信息
//pUSR_ACCOUNT add_usr_account(pUSR_ACCOUNT *pUsr_Account_List,USR_ACCOUNT_NUM *usr_account_num);
pUSR_ACCOUNT add_usr_account(List<pUSR_ACCOUNT>& user);
//增加账户信息，返回指向当前帐号的指针
//pUSR_ACCOUNT update_usr_account(pUSR_ACCOUNT pUsr_Account_List,char* search_name);
pUSR_ACCOUNT update_usr_account(List<pUSR_ACCOUNT> &user,string& search_name);
//修改帐号信息返回指向当前修改帐号的信息
//pUSR_ACCOUNT delete_usr_account(pUSR_ACCOUNT *pUsr_Account_List,USR_ACCOUNT_NUM* usr_account_num,char* search_name);
pUSR_ACCOUNT delete_usr_account(List<pUSR_ACCOUNT> &user,string& search_name);
//删除帐号信息，返回指向下一个帐号的指针
//void save_data_to_file(char *config_file_name,pUSR_ACCOUNT pUsr_Account_List,pUSR_INFOR pUsr_Infor_List);
void save_data_to_file(const char* config_file_name,List<pUSR_ACCOUNT> &user,List<pUSR_INFOR> &student);
//将学生信息和帐号信息保存到文件里去

#endif
