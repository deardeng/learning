#include <process.h>
#include "JThread.h"

JThread::JThread():hThread_(NULL),threadId_(0){

}

JThread::~JThread(){
	if(hThread_ != NULL)
		CloseHandle(hThread_);
}

unsigned _stdcall JThread::ThreadFun(void* p){
	JThread* jtp  = (JThread*)p;
	jtp->Run();
	return 0;
}

bool JThread::Start(){
	hThread_ = (HANDLE)_beginthreadex(NULL,0,ThreadFun,this,0,&threadId_);
	return hThread_ != NULL;
}

void JThread::Wait(DWORD timeout){
	WaitForSingleObject(hThread_,timeout);
}