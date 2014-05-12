/*标准容器（类标准）的共性：vector,deque,list,set/map,multi...
 * 构造函数：无参构造，拷贝构造，区间构造（两个迭代器表示两个的位置）
 * 析构:
 * 迭代器相关：正向.begin()指向第一个元素的迭代器，.end()指向超越最后一个元素的迭代器，.rbegin()指向反向第一个元素位置的迭代器，.rend()指向反向最后一个元素的迭代器。
 * iterator,reverse_iterator,const_iterator,const_reverse_iterator
 * ->,=,*,++,==,!=,--
 * 插入：.insert(pos,.element),pos是一个迭代器，表示位置
 * 删除：.erase(pos),.erase(pos_beg,pos_end)
 * 清除：.clear()
 * 大小：.size(),.max_size(),.empty()
 * 交换：.swap(c2),swap(c1,c2)
 * 运算符：=,>,<,>=,<=,==,!=
 */

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include"print.h"
int main(){
	int a[5]={33,11,55,22,44};
	vector<int> vi(a,a+5);
	cout << vi.size() << endl;
	sort(vi.begin(),vi.end());//只能是数组,vector和deque
	vector<int>::iterator b = vi.begin();
	while(b!=vi.end())
		cout << *b++ << ' ';
	cout << endl;
	for(int i=0;i<5;i++)
		cout << a[i] << ',';
	cout << endl;
	print(vi.begin(),vi.end());
	print(a,a+5);
	print(vi.rbegin(),vi.rend());
	b = vi.begin();
	vi.insert(++++b,66);
	vi.insert(vi.begin(),77);
	vi.insert(vi.end(),88);
	print(vi.begin(),vi.end());
	cout << vi.size() << '/' << vi.max_size() << endl;
	vi.erase(------vi.end());
	print(vi.begin(),vi.end());
	vi.erase(++++vi.begin(),--vi.end());
	print(vi.begin(),vi.end());
	vector<int> v2(a,a+5);
	print(v2.begin(),v2.end());
	vi.swap(v2);
	cout << "===================" << endl;
	print(vi.begin(),vi.end());
	print(v2.begin(),v2.end());
	swap(vi,v2);
	cout << "===================" << endl;
	print(vi.begin(),vi.end());
	print(v2.begin(),v2.end());
	cout << "===================" << endl;
	vector<int> t =vi;
	vi = v2;
	v2 = t;
	print(vi.begin(),vi.end());
	print(v2.begin(),v2.end());
	vi.clear();
	cout << vi.size() << endl;
	print(vi.begin(),vi.end());
	vector<int> x;
	cout << "vector当前容量：" << x.capacity() << endl;
	
}