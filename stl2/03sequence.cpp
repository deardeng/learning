/*序列式容器的共性：vector,deque,list
 * 构造函数：制定元素个性和初始值（初始值默认为零初始化）
 * 插入：.insert(pos,n,element),.insert(pos,pos_beg,pos_end)
 * 赋值：.assign(n,element),.assign(pos_beg,pos_end)
 * 调整：.resize(n,element=默认零初始化)
 * 首位：.front(),.back()
 * 增删：.push_back(element),.pop_back()只删除，返回void
 */
#include<deque>
#include<iostream>
using namespace std;
#include"print.h"
#include<string>

int main()
{
	deque<string> ds;
//	deque<vector<int> >
	ds.push_back("曾文武");
	ds.push_back("赵旭泽");
	ds.push_back("薛小娟");
	ds.push_back("高上");
	print(ds.begin(),ds.end(),',');
	ds.insert(++++ds.begin(),2,"芙蓉");
	print(ds.begin(),ds.end(),',');
	string s[3]={"张彦春","张永香","刘克磊"};
	ds.insert(----ds.end(),s,s+3);
	print(ds.begin(),ds.end(),',');
	ds.pop_back();ds.pop_back();
	print(ds.begin(),ds.end(),',');
	cout << "front:" << ds.front() << ",back:" << ds.back() << endl;
	ds.resize(12,"郭宜如");
	print(ds.begin(),ds.end(),',');
	ds.assign(5,"康森林");
	print(ds.begin(),ds.end(),',');
	ds.front() = "孙冬冬";
	ds.back() = "梁振杰";
	print(ds.begin(),ds.end(),',');
}