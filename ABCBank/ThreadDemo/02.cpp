#include <windows.h>
#include <process.h>
#include <iostream>
using namespace std;

unsigned _stdcall ThreadProc(void* lpParameter){
	cout << "GetCurrentThreadId() = " << GetCurrentThreadId() << endl;
	int n = (int)lpParameter;
	while(n--){
		cout << "this is a test" << endl;
		Sleep(1000);
	}
	return 100;
}
int main(){
	unsigned threadId;
	HANDLE hThread = (HANDLE)_beginthreadex(NULL,0,ThreadProc,(void*)5,0,&threadId);
	if(hThread == NULL){
		cout << "error with code" << GetLastError() << endl;
		exit(1);
	}

	cout << "threadId = " << threadId << endl;

	SuspendThread(hThread);
	ResumeThread(hThread);


	DWORD ret;
	ret = WaitForSingleObject(hThread,INFINITE);
	if(WAIT_OBJECT_0 == ret){
		cout << "wait succ" << endl;
	}
	else if(WAIT_FAILED == ret){
		cout << "error with code" << GetLastError() << endl;
		exit(1);
	}

	CloseHandle(hThread);
	return 0;
}