/*multimap的个性：
 * 允许重复key
 * 元素是key/value对
 * 不支持方括号下标
 */
#include<map>
#include<iostream>
using namespace std;
#include"print.h"
#include<string>
int main(){
	typedef multimap<string,double> MSD;
	MSD m;
	m.insert(MSD::value_type("王刚",100000));
	m.insert(make_pair("何军军",120000)); 
	m.insert(make_pair("杨勇",20000));
	m.insert(make_pair("何军军",160000)); 
	m.insert(make_pair("杨勇",3000));
	m.insert(MSD::value_type("王刚",220000));
	m.insert(MSD::value_type("王刚",150000));
	m.insert(make_pair("何军军",130000)); 
	m.insert(make_pair("杨勇",1000000));
	m.insert(make_pair("杨勇",110000));
	print(m.begin(),m.end());
	MSD::iterator ib = m.begin(),ie;
	MSD cnt;
	while(ib!=m.end()){
		string name = ib->first;
		ie = m.upper_bound(name);
		double sum = 0.0;
		while(ib!=ie)sum += ib++->second;
		cnt.insert(make_pair(name,sum*0.03));
	}
	print(cnt.begin(),cnt.end());
}