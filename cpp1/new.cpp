#include <iostream>
using namespace std;
#include <cstdlib>
#include <string>
#include <new>
//new ����==>(����*)malloc(sizeof(����))
int main()
{
	string* p = static_cast<string*>(malloc(sizeof(string)));
	int* q = new int;//����֤��0
	int* r = new int(888);
	cout << *q << ',' << *r << endl;
	int n;
	cout << "������һ������:";
	cin >> n;
	int* a = new(nothrow) int[n];//����֤����
	if(a==NULL){
		cout << n*sizeof(int) << "����ʧ��" << endl;
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
	free(p);//malloc����Ĳ�Ҫ��delete p�ͷ�
}

