/*list的个性:双向链表
 * 增删：.push_front(element),.pop_front(),.remove(element)//==
 * 不支持下标[]
 * 除重：.unique()只管相邻的,相邻的重复元素只保留一个
 * 排序：.sort(compare_func=less)默认用小于符号来比较，从小到大排序//<
 * 倒置：.reverse()颠倒链表中元素顺序
 * 转移：.splice(pos,list2),.splice(pos,list2,pos2),
 * .splice(pos,list2,pos_beg,pos_end)
 * 归并：.merge(list2)
 */
#include<iostream>
using namespace std;
#include<list>
#include"print.h"
#include<cassert>
bool compare(int x,int y){
	x%=3,y%=3;
	return x<y;
}

int main(){
	int a[10]={3,8,8,8,5,5,1,8,8,7},b[6]={9,3,5,2,7,6};
	list<int> li(a,a+10),lili(b,b+6);
	print(li.begin(),li.end());
	li.unique();
	print(li.begin(),li.end());
	li.sort();
	print(li.begin(),li.end());
	li.unique();
	print(li.begin(),li.end());
	li.reverse();
	print(li.begin(),li.end());
	li.splice(li.begin(),lili);
	cout << "======================" << endl;
	print(li.begin(),li.end());
	cout << "======================" << endl;
	assert(lili.empty());
	li.remove(5);
	print(li.begin(),li.end());
	li.sort();li.unique();
	print(li.begin(),li.end());
	lili.push_back(0);
	lili.push_back(4);
	lili.push_back(7);
	lili.push_back(5);
	lili.push_back(10);
	lili.sort();
	print(lili.begin(),lili.end());
	li.merge(lili);
	print(li.begin(),li.end());
	lili.assign(b,b+6);
	print(lili.begin(),lili.end());
	lili.sort(greater<int>());
	print(lili.begin(),lili.end());
	lili.sort(compare);
	print(lili.begin(),lili.end());
}