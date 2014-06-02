#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

int fileToVector(const string& fileName,vector<string>& svec){
    ifstream inFile(fileName.c_str());
    if(!inFile)
        return 1;

    string s;
    while(getline(inFile,s))
        svec.push_back(s);
    inFile.close();
    if(inFile.eof())
        return 4;
    if(inFile.bad())
        return 2;
    if(inFile.fail())
        return 3;
}

int main(){
    vector<string> svec;
    string fileName,s;

    cout << "Enter filename :" << endl;
    cin >> fileName;

    switch(fileToVector(fileName,svec)){
        case 1:
            cout << "error: can not to open file: " << fileName << endl;
            return -1;
        case 2:
            cout << "error: system failure " << endl;
            return -1;
        case 3:
            cout << "error: read failure " << endl;
            return -1;
    }

    string word;
    istringstream isstream;
    for(vector<string>::iterator iter = svec.begin();iter != svec.end();++iter){
        isstream.str(*iter);
        while(isstream >> word /*&& !isstream.eof()*/){//字符串流没有相应的结束标志。
//对字符串流的几点说明：
//(1) 输出时数据不是流向外存文件,而是流向内存中的一个存储空间。输入时从内存中的存储空间读取数据。
//(2) 字符串流对象关联的不是文件,而是内存中的一个字符数组,因此不需要打开和关闭文件。
//(3) 每个文件的最后都有一个文件结束符,表示文件的结束。
//而字符串流所关联的字符数组中没有相应的结束标志,
//用户要指定一个特殊字符作为结束符,
//在向字符数组写入全部数据后要写入此字符。
            cout << word << endl;
        }
        isstream.clear();
    }
    return 0;
}
