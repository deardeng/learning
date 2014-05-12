#include <iostream>
using namespace std;
#include <cstdlib>
#include <string>
#include <new>
//new 类型==>(类型*)malloc(sizeof(类型))
int main()
{
	string* p = static_cast<string*>(malloc(sizeof(string)));
	int* q = new int;//不保证是0
	int* r = new int(888);
	cout << *q << ',' << *r << endl;
	int n;
	cout << "请输入一个整数:";
	cin >> n;
	int* a = new(nothrow) int[n];//不保证清零
	if(a==NULL){
		cout << n*sizeof(int) << "申请失败" << endl;
	}
	else{
		for(int i=0; i<n; i++){
			cout << a[i] << ' ';
			if(a[i]){
				cout << flush;
				char c;
			cin >> c;
			}
		}
		cout << endl;
	}
	delete r;r=NULL;
	delete q;q=NULL;
	delete[] a;a=NULL;
	free(p);//malloc申请的不要用delete p释放
}

