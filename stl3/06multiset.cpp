/*multiset的个性：
 * 元素就是key
 * 允许有重复的key
 */
#include<set>
#include<iostream>
using namespace std;
#include"print.h"
#include<map>

int main(){
	multiset<string> ms;
	string name;
	cout << "请输入你选举的人的姓名（end表示结束）：" << endl;;
	while(cin>>name){//Ctrl+D表示输入结束
		ms.insert(name);
	}
	print(ms.begin(),ms.end());
	multiset<string>::iterator ib=ms.begin(),ie;
	multimap<int,string> mis;
	while(ib!=ms.end()){
		mis.insert(make_pair(ms.count(*ib),*ib));
		ib=ms.upper_bound(*ib);
	}
	print(mis.begin(),mis.end(),'\n');
}