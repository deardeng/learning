#include <iostream>
using namespace std;
#include "list.h"
#include "sims.h"
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include "passwd.h"

int main()
{
    const char* config_file_name="Configure.txt";
    List<pUSR_ACCOUNT> user;
    List<pUSR_INFOR> student;
    USR_ACCOUNT_NUM usr_account_num;
    USR_INFOR_NUM usr_infor_num;
    system_init(config_file_name,user,student,usr_account_num,usr_infor_num);
    cout << "here:" << endl;
    cout << "the number info:" << usr_infor_num << endl;
    string username;
    cout << "input your username:";
    cin >> username;
    cin.ignore();//must!
    string password;
    password=inputpasswd();
    cout << endl;
    int select_system_num=-1;
    int who=role_confirm(user,username,password);
    int studentid;
    string rolename;
    while(1){
        show_system_menu(who,select_system_num);
        switch(select_system_num){
            case 0:Usr_Infor_Show(student);
                   sleep(2);
                   break;

            case 1:call_search_menu(student,who);
                   break;
            case 2:cout << "add a student,input a id: ";
                   cin >> studentid;
                   add_usr_infor(student,studentid);
                   break;
            case 3:cout << "update a student information,input his id: ";
                   cin >> studentid;
                   update_usr_infor(student,studentid);
                   break;
            case 4:cout << "delete a student information,input his id: ";
                   cin >> studentid;
                   delete_usr_infor(student,studentid);
                   break;
            case 5:add_usr_account(user);
                   break;
            case 6:update_usr_account(user,rolename);
                   break;
            case 7:cout << "delete a user information: ";
                   cin >> rolename;
                   delete_usr_account(user,rolename);
                   break;
            case 8:cout << "search a user: ";
                   cin >> rolename;
                   search_usr_account(user,rolename);
                   sleep(2);
                   break;
            case 9:Usr_Account_Show(user);
                   sleep(2);
                   break;
            case 10:save_data_to_file(config_file_name,user,student);
                    sleep(1);
                    break;
            case 11:return 0;
            default:break;
        }
    }
    //string rolename;
    //cout << "search a user:" << endl;
    //cin >> rolename;
    //search_usr_account(user,rolename);
    //add_usr_account(user);
    //cout << "======================================" << endl;
    //string userr;
    //cout << "update a user information." << endl;
    //cin >> userr;
    //update_usr_account(user,userr);
    //cout << "======================================" << endl;
    //Usr_Account_Show(user);
    //cout << "delete a user information." << endl;
    //cin >> userr;
    //delete_usr_account(user,userr);
    //cout << "======================================" << endl;
    //Usr_Account_Show(user);
    //Usr_Infor_show(student);
    //save_data_to_file(config_file_name,user,student);
    //cout << "======================================" << endl;
}
