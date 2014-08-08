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

void Usr_Account_Show(const List<pUSR_ACCOUNT> &who){
    who.travel_user();
}

void Usr_Infor_Show(const List<pUSR_INFOR> &who){
    who.travel_student();
}

int system_init(const char* config_file_name,List<pUSR_ACCOUNT>& user,List<pUSR_INFOR>& student,USR_ACCOUNT_NUM &usr_account_num,USR_INFOR_NUM &usr_infor_num){
    ifstream f1(config_file_name,ios::binary|ios::in);
    if(!f1){
        cout << "open" << config_file_name << "error";
        return 1;
    }
    char buf[1000];


    f1.getline(buf,sizeof(buf));
    cout << "Loading--->" << buf << ':';
    ifstream f2(buf,ios::binary|ios::in);//open Usr_account.txt
    if(!f2){
        cout << "open" << buf << "error" << endl;
        return 1;
    }
    else{
        memset(buf,0,sizeof(buf));
        pUSR_ACCOUNT nodeu=new USR_ACCOUNT;
        while(f2 >> nodeu->usr_name >> nodeu->usr_pwd >> nodeu->usr_role){
            user.push_back(nodeu);
            nodeu=new USR_ACCOUNT;
        }
    }
    cout << "ok" << endl;


    f1.getline(buf,sizeof(buf));
    cout <<"Loading--->" << buf << ' ';
    ifstream f3(buf,ios::binary|ios::in);//open Usr_info.txt
    if(!f3){
        cout << "open" << buf << "error";
        return 1;
    }
    else{
        memset(buf,0,sizeof(buf));
        pUSR_INFOR nodes=new USR_INFOR;
        while(f3 >> nodes->usr_id >> nodes->usr_name >> nodes->usr_course_id >> nodes->usr_course_score){
            student.push_back(nodes);
            nodes=new USR_INFOR;
        }
        cout << "ok" << endl;
    }
    usr_infor_num= student.size();
    f1.close();
    f2.close();
    f3.close();
    return 0;
}

USR_ROLE role_confirm(List<pUSR_ACCOUNT>& user,const string& username ,USR_ACCOUNT_NUM& usr_account_num){
    int len=user.size();
    for(int i=0;i<len;i++)
        if(user.getptr(i)->data->usr_name==username){
            if(user.getptr(i)->data->usr_pwd==usr_account_num){
                if(user.getptr(i)->data->usr_role==1)
                    return true;
                else
                    return false;
            }
            else
                exit(-1);
        }
    exit(-1);
}
int show_system_menu(USR_ROLE role,int &select_system_num){
    system("clear");
    cout << "**********************************************************" << endl;
    cout << "***********Student Information Management System**********" << endl;
    cout << "**********************************************************" << endl;
    cout << endl;
    if(role==1){//admin
        cout << "            0.print student information(show 2 seconds)" << endl;
        cout << "            1.search student information" << endl;
        cout << "            2.add student information   " << endl;
        cout << "            3.update student information" << endl;
        cout << "            4.delete student information" << endl;
        cout << "            5.add user account          " << endl;
        cout << "            6.update user account       " << endl;
        cout << "            7.delete user account       " << endl;
        cout << "            8.search user account       " << endl;
        cout << "            9.print user information(show 2 seconds)" << endl;
        cout << "            10.save to file             " << endl;
        cout << "            11.exit                      " << endl;
        cout << "select a number:";
        cin >> select_system_num;
        return 1;
    }
    else if(role==0){//user
        cout << "            0.print student information" << endl;
        cout << "            1.search student information" << endl;
        cout << "            11.exit                      " << endl;
        cout << "select a number:";
        cin >> select_system_num;
        return 0;
    }
    return -1;
}
int show_search_menu(USR_ROLE role,int &select_search_num){
    system("clear");
    if(role==1){//admin
        cout << "0.search all" << endl;
        cout << "1.search by name" << endl;
        cout << "2.search by id" << endl;
        cout << "3.return" << endl;
        cout << "select a number:";
        cin >> select_search_num;
        return 1;
    }
    else if(role==0){//user
        cout << "1.search by name" << endl;
        cout << "2.search by id" << endl;
        cout << "3.return" << endl;
        cout << "select a number:";
        cin >> select_search_num;
        return 0;
    }
    return -1;
}

void call_search_menu(List<pUSR_INFOR>& student,USR_ROLE role){
    int student_id=-1;
    string studentname;
    int flag=1;
    int select_search_num=-1;
    while(flag){
        show_search_menu(role,select_search_num);
        switch(select_search_num){
            case 0:Usr_Infor_Show(student);
                   sleep(3);
                   break;
            case 1:cout << "input a student's name: ";
                   cin >> studentname;
                   search_usr_infor_by_name(student,studentname);
                   sleep(3);
                   break;
            case 2:cout << "input a student's id: ";
                   cin >> student_id;
                   search_usr_infor_by_id(student,student_id);
                   sleep(3);
                   break;
            case 3:flag=0;
                   break;
        }
    }
}

void search_usr_infor_by_id(List<pUSR_INFOR>& student,SEARCH_ID& search_id){
    int len=student.size();
    for(int i=0;i<len;i++)
        if(student.getptr(i)->data->usr_id==search_id){
            cout << "The student's information: " << endl;
            cout << "The student's name: "<<student.getptr(i)->data->usr_name<< endl;
            cout << "The student's id: "<<student.getptr(i)->data->usr_id << endl;
            cout << "The student's course id: "<<student.getptr(i)->data->usr_course_id<< endl;
            cout << "The student's course score: "<<student.getptr(i)->data->usr_course_score<< endl;
            return ;
        }
    cout << "can't find the student." << endl;
}

void search_usr_infor_by_name(List<pUSR_INFOR>& student,string& search_name){
    int len=student.size();
    for(int i=0;i<len;i++)
        if(student.getptr(i)->data->usr_name==search_name){
            cout << "The student's information: " << endl;
            cout << "The student's name: "<<student.getptr(i)->data->usr_name<< endl;
            cout << "The student's id: "<<student.getptr(i)->data->usr_id << endl;
            cout << "The student's course id: "<<student.getptr(i)->data->usr_course_id<< endl;
            cout << "The student's course score: "<<student.getptr(i)->data->usr_course_score<< endl;
            return ;
        }
    cout << "can't find the student." << endl;
}
pUSR_INFOR add_usr_infor(List<pUSR_INFOR>& student,USR_INFOR_NUM& usr_infor_num){
    int len=student.size();
    int i;
    for(i=0;i<len;i++){
        if(student.getptr(i)->data->usr_id==usr_infor_num){
            return NULL;
        }
        if(student.getptr(i)->data->usr_id<usr_infor_num)
            continue;
        if(student.getptr(i)->data->usr_id>usr_infor_num){
            pUSR_INFOR newnode=new USR_INFOR;
            char *name=new char[20];
            cout << "input the new student's name:";
            cin >> name;
            strcpy(newnode->usr_name,name);//name
            name[strlen(name)]='\0';

            newnode->usr_id=usr_infor_num;//id

            int *studentcourseid=new int;
            cout << "input the new student's course id:";
            cin >> *studentcourseid;
            newnode->usr_course_id=*studentcourseid;//course_id

            int *studentcoursescore=new int;
            cout << "input the new student's course score:";
            cin >> *studentcoursescore;
            newnode->usr_course_score=*studentcoursescore;//course_score

            student.insert(newnode,i);
            return newnode;
        }
    }
    if(i==len){
        pUSR_INFOR newnode=new USR_INFOR;
        char *name=new char[20];
        cout << "input the new student's name:";
        cin >> name;
        strcpy(newnode->usr_name,name);//name
        name[strlen(name)]='\0';

        newnode->usr_id=usr_infor_num;//id

        int *studentcourseid=new int;
        cout << "input the new student's course id:";
        cin >> *studentcourseid;
        newnode->usr_course_id=*studentcourseid;//course_id

        int *studentcoursescore=new int;
        cout << "input the new student's course score:";
        cin >> *studentcoursescore;
        newnode->usr_course_score=*studentcoursescore;//course_score

        student.push_back(newnode);
        return newnode;
    }
    //save_data_to_file
    return NULL;
}
pUSR_INFOR update_usr_infor(List<pUSR_INFOR>& student,SEARCH_ID search_id){
    int len = student.size();
    for(int i=0;i<len;i++){
        if(student.getptr(i)->data->usr_id==search_id){
            char name[20];
            cout << "update the student's name: ";
            cin >> name;
            strcpy(student.getptr(i)->data->usr_name,name);//name

            int studentcourseid;
            cout << "update the student's course id:";
            cin >> studentcourseid;
            student.getptr(i)->data->usr_course_id=studentcourseid;//course_id

            int studentcoursescore;
            cout << "update the student's course score:";
            cin >> studentcoursescore;
            student.getptr(i)->data->usr_course_score=studentcoursescore;//course_score
            //save_data_to_file
            return student.getptr(i)->data;
        }
    }
    cout << "can't find id:" << search_id << " student." << endl;
    //save_data_to_file
    return NULL;
}

pUSR_INFOR delete_usr_infor(List<pUSR_INFOR>& student,SEARCH_ID search_id){
    int len=student.size();
    for(int i=0;i<len;i++){
        if(student.getptr(i)->data->usr_id==search_id){
            student.erase(i);
            //save_data_to_file
            if(i==len-1)
                return NULL;
            else
                return student.getptr(i)->data;
        }
    }
    cout << "can't find id:" << search_id << " student." << endl;
    //save_data_to_file
    return NULL;
}

void search_usr_account(List<pUSR_ACCOUNT>& user,string& search_name){
    int len=user.size();
    for(int i=0;i<len;i++)
        if(user.getptr(i)->data->usr_name==search_name){
            cout << "the user's name :" << user.getptr(i)->data->usr_name << endl;
            cout << "the user's password :" << user.getptr(i)->data->usr_pwd<< endl;
            string a=user.getptr(i)->data->usr_role?"admin":"general user";
            cout << "the user's role: " << a << endl;
            return ;
        }
    cout << "can't find the user" << endl;
}

pUSR_ACCOUNT add_usr_account(List<pUSR_ACCOUNT>& user){
    int len=user.size();
    char *name=new char[20];
    cout << "add a user,input his name:";
    cin >> name;
    int i;
    for(i=0;i<len;i++){
        while(1){
            if(!strcmp(user.getptr(i)->data->usr_name,name)){
                cout << "datebase has this name,please use other name:";
                cin >> name;
            }
            else
                break;
        }
    }
    pUSR_ACCOUNT newnode=new USR_ACCOUNT;
    strcpy(newnode->usr_name,name);//name

    char *passwd=new char[100];
    cout << "input new user's password:";
    cin >> passwd;
    strcpy(newnode->usr_pwd,passwd);//password

    newnode->usr_role=0;//general user

    i=0;
    while(i<len)
        i++;

    user.insert(newnode,i);
    //save_data_to_file
    return user.back();
}

pUSR_ACCOUNT update_usr_account(List<pUSR_ACCOUNT> &user,string& search_name){
    int len=user.size();
    for(int i=0;i<len;i++){
        if(user.getptr(i)->data->usr_name==search_name){
            char name[20];
            cout << "update the user's name: ";
            cin >> name;
            strcpy(user.getptr(i)->data->usr_name,name);//name

            char passwd[100];
            cout << "update the user's password: ";
            cin >> passwd;
            strcpy(user.getptr(i)->data->usr_pwd,passwd);//password

            bool userrole;
            cout << "update the user's role (1.admin 0.general user)";
            cin >> userrole;
            user.getptr(i)->data->usr_role=userrole;
            //save_data_to_file

            return user.getptr(i)->data;
        }
    }
    cout << "can't find " << search_name << endl;
    //save_data_to_file
    return NULL;
}

pUSR_ACCOUNT delete_usr_account(List<pUSR_ACCOUNT> &user,string& search_name){
    int len=user.size();
    for(int i=0;i<len;i++){
        if(user.getptr(i)->data->usr_name==search_name){
            user.erase(i);
            //save_data_to_file
            if(i==len-1)
                return NULL;
            else
                return user.getptr(i)->data;
        }
    }
    cout << "can't find " << search_name << endl;
    //save_data_to_file
    return NULL;
}

void save_data_to_file(const char* config_file_name,List<pUSR_ACCOUNT> &user,List<pUSR_INFOR> &student){
    ifstream f1(config_file_name,ios::in);
    if(!f1){
        cout << "open" << config_file_name << "error" << endl;
        return ;
    }
    char buf[1000];

    f1.getline(buf,sizeof(buf));
    cout << "Writing--->" << buf << ':';
    ofstream f2(buf,ios::out);//user
    if(!f2){
        cout << "open" << buf << "error" << endl;
        return ;
    }
    else{
        memset(buf,0,sizeof(buf));
        int len=user.size();
        for(int i=0;i<len;i++){
            f2 << user.getptr(i)->data->usr_name <<' '
                << user.getptr(i)->data->usr_pwd << ' '
                << user.getptr(i)->data->usr_role << ' ';
        }
    }
    cout << "ok" << endl;

    f1.getline(buf,sizeof(buf));
    cout << "Writing--->" << buf << ':';
    ofstream f3(buf,ios::out);//student
    if(!f3){
        cout << "open" << buf << "error" << endl;
        return;
    }
    else{
        memset(buf,0,sizeof(buf));
        int len=student.size();
        for(int i=0;i<len;i++){
            f3 << student.getptr(i)->data->usr_id<< ' '
                << student.getptr(i)->data->usr_name << ' '
                << student.getptr(i)->data->usr_course_id << ' '
                << student.getptr(i)->data->usr_course_score << ' ';
        }
    }
    cout << "ok" << endl;
    f1.close();
    f2.close();
    f3.close();
}

