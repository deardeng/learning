#include <map>
#include <string>
#include <iostream>
using namespace std;

int main(void){
	//���뵽map�����ڲ���Ԫ��Ĭ���ǰ���key��С����������
	//key����һ��Ҫ����<�����
	map<string,int> mapTest;
	mapTest["aaa"] = 100;	//int& operator[](const string& index);

	mapTest["eee"]=300;
	mapTest.insert(map<string,int>::value_type("bbb",200));

	mapTest.insert(pair<string,int>("ccc",300));

	mapTest.insert(make_pair("ddd",400));



	int n=mapTest["bbb"];
	cout << n << endl;
	mapTest["bbb"]=2000;
	mapTest.erase("bbb");
	
	map<string,int>::const_iterator it;
	it=mapTest.find("ccc");
	if(it!=mapTest.end()){
		mapTest.erase(it);
	}
	for(it=mapTest.begin();it!=mapTest.end();++it){
		cout << it->first << ' ' <<it->second << endl;
	}
	return 0;
}