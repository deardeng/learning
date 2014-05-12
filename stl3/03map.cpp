/*map的个性：
 * 不允许key重复
 * 元素是key/value对
 * 支持以key为下标取得访问对应的value的引用，如果key不存在就新增一个元素以这个为key，value用零初始化
 */
#include<iostream>
using namespace std;
#include<map>
#include"print.h"
struct P{
	string name;
	int age;
public:
	P(){}
	P(const char* n,int a):name(n),age(a){}
};
ostream& operator<<(ostream& o,const P& x){
	return o<< x.name << ':' << x.age;
}


int main()
{
	map<int,P> mis;
	mis.insert(map<int,P>::value_type(8,P("王龙",20)));
	mis.insert(pair<int,P>(5,P("钟玉龙",22)));
	mis.insert(make_pair(4,P("李霖",21)));
	mis[3]= P("何军军",20);
	mis[6] = P("蒲嗣良",23);
	mis.insert(make_pair(5,P("芙蓉",18)));
	print(mis.begin(),mis.end());
	mis[6] = P("蒲松龄",300);
	print(mis.begin(),mis.end());
}