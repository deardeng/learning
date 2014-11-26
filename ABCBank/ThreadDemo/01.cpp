#include <windows.h>
#include <iostream>
using namespace std;

DWORD WINAPI ThreadProc(LPVOID lpParameter){
	cout << "GetCurrentThreadId() = " << GetCurrentThreadId() << endl;
	int n = (int)lpParameter;
	while(n--){
		cout << "this is a test" << endl;
		Sleep(1000);
	}
	return 100;
}
int main(){
	DWORD dwThreadId;
	HANDLE hThread = CreateThread(NULL,0,ThreadProc,(LPVOID)5,0,&dwThreadId);
	if(hThread == NULL){
		cout << "error with code" << GetLastError() << endl;
		exit(1);
	}
	
	cout << "dwThreadId = " << dwThreadId << endl;

	SuspendThread(hThread);
	ResumeThread(hThread);

	//DWORD exitCode = 0;
	//do{
	//	GetExitCodeThread(hThread,&exitCode);
	//}while(STILL_ACTIVE == exitCode);

	//cout << "exitCode = " << exitCode << endl;

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