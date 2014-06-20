#include <vector>
#include <iostream>
using namespace std;
#include <algorithm>
typedef vector<int> INTVEC;

//void ShowVec(const INTVEC& v){
//	unsigned int i;
//	for(i=0;i<v.size();i++){
//		cout << v[i] << ' ';
//	}
//	cout << endl;
//}

//++运算符，后++多一次临时对象的构造，比前++效率低。
//void ShowVec(INTVEC& v){
//	INTVEC::iterator it;
//	for(it=v.begin();it!=v.end();++it){
//		cout << *it << ' ';
//	}
//	cout << endl;
//}

void ShowVec(const INTVEC& v){
		INTVEC::const_iterator it;
		for(it=v.begin();it!=v.end();++it){
			cout << *it << ' ';
		}
		cout << endl;
}
int main(void){
	//string
	//basic_string<char>
	INTVEC v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	/*cout << v.back() << endl;
	v.pop_back()*/;
	
	ShowVec(v);
	//v.erase(v.begin()+2);
	//v.erase(v.begin(),v.begin()+2);
	v.erase(remove(v.begin(),v.end(),3),v.end());
	ShowVec(v);
	return 0;
}