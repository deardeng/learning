/*map的个性：
 * 不允许key重复
 * 元素是key/value对
 * 支持以key为下标取得访问对应的value的引用，如果key不存在就新增一个元素以这个为key，value用零初始化
 */
#include<iostream>
using namespace std;
#include<map>
#include"print.h"

int main()
{
	map<int,Person> mis;
	mis.insert(map<int,string>::value_type(5,"钟玉龙"));
	mis.insert(pair<int,string>(8,"王龙"));
	mis.insert(make_pair(4,"李霖"));
	mis[3]="何军军";
	mis[6] = "蒲嗣良";
	mis.insert(make_pair(5,"钟玉龙"));
	mis.insert(make_pair(5,"芙蓉"));
	print(mis.begin(),mis.end());
	mis[6] = "蒲松龄";
	print(mis.begin(),mis.end());
}