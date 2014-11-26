#include <windows.h>
#include <process.h>
#include <iostream>
using namespace std;
#include "JThread.h"

class TestThread:public JThread{
public:
	TestThread(int n):n_(n){
	}
	~TestThread(){
	}
	void Run(){
		while(n_--){
			cout << "this is a test" << endl;
			Sleep(1000);
		}

	}
private:
	int n_;
};
int main(){
	TestThread t(5);
	t.Start();
	t.Wait();
	return 0;
}