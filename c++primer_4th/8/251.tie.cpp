#include<iostream>
using namespace std;
#include<fstream>

int main(){
    ofstream ofs;
    ofs.open("test.txt");

    ostream *old_tie=cin.tie(&ofs);//带一个输出流指针作为参数，重新设置绑定的对象，并返回前任（此处cout）绑定对象（指针）
    *cin.tie()/* 等于ofs */ << "There will be some text:";//不带参数执行，返回绑定的输出流指针（此处ofs）
    ofs << "ofs???";
    *old_tie/* 等于cout */ << "Right???";
    char c;
    while(cin >> c){
        ofs << c;
    }

    ofs.close();
    return 0;
}
/* watch -d -n 1 test.txt 此命令可以实时查看test.txt文件 */
