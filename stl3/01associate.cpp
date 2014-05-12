/*关联式容器共性：都是用二叉查找树实现的，都自动根据关键字排序
 * set<K>, multiset<K>, map<K,V>,multimap<K,V>
 * 查找：.find(key)返回一个迭代器指向第一个元素,失败返回.end()
 * 统计：.count(key)统计关键字等于key的元素的个数
 * 删除：.erase(key)删除关键字等于key的所有元素
 * 区间：.lower_bound(key)取得关键字为key的第一个元素的位置，
 * .upper_bound(key)取得关键字为key的最后一个元素之后的位置，
 * .equal_range(key)一次取得关键字为key的元素的区间，返回一个pair
 * 插入：.insert(element)
 * 构造函数：可以用比较函数作为参数bool(*compare)(K a,K b)
 */

#include<set>
#include<iostream>
using namespace std;
#include"../stl2/print.h"
struct Person{
	string name;
	int age;
public:
	Person(const char* n,int a):name(n),age(a){}
};
bool operator<(const Person& a,const Person& b){
	return a.age<b.age|| a.age==b.age&&a.name<b.name;
}
ostream& operator<<(ostream& o,const Person& x){
	return o<< x.name << ':' << x.age;
}
int main()
{
	multiset<Person> mp;
	mp.insert(Person("赵元培",26));
	mp.insert(Person("郭益如",18));
	mp.insert(Person("姚连斌",20));
	mp.insert(Person("赵元培",26));
	mp.insert(Person("赵元培",26));
	mp.insert(Person("王臣彬",21));
	mp.insert(Person("郭益如",18));
	mp.insert(Person("姚连斌",20));
	mp.insert(Person("张洪铭",22));
	mp.insert(Person("赵元培",26));
	mp.insert(Person("郭益如",18));
	mp.insert(Person("王臣彬",21));
	mp.insert(Person("郭益如",18));
	mp.insert(Person("王臣彬",21));
	mp.insert(Person("郭益如",18));
	print(mp.begin(),mp.end());
	multiset<Person>::iterator it = mp.find(Person("张洪铭",22));
	if(it == mp.end()) cout << "没有找到芙蓉" << endl;
	else cout << "发现目标:" << *it << endl;
	it = mp.find(Person("芙蓉",22));
	if(it == mp.end()) cout << "没有找到芙蓉" << endl;
	else cout << "发现目标:" << *it << endl;
	it = mp.find(Person("郭益如",18));
	cout << mp.count(*it) << "个" << *it << endl;
	it = mp.find(Person("赵元培",26));
	cout << mp.count(*it) << "个" << *it << endl;
	multiset<Person>::iterator ib,ie;
	ib = mp.lower_bound(Person("王臣彬",21));
	ie = mp.upper_bound(Person("王臣彬",21));
	cout << "======================" << endl;
	print(ib,ie);
	pair<multiset<Person>::iterator,multiset<Person>::iterator> p = mp.equal_range(Person("姚连斌",20));
	print(p.first,p.second);
	typedef multiset<Person>::iterator Iter;
	pair<Iter,Iter> q = mp.equal_range(Person("郭益如",18));
	print(q.first,q.second);
	cout << "======================" << endl;
	mp.erase(Person("郭益如",18));
	mp.erase(Person("赵元培",26));
	print(mp.begin(),mp.end());
}