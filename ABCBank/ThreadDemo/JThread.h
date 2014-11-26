#ifndef _JTHREAD_H_
#define _JTHREAD_H_

#include <Windows.h>
class JThread{
public:
	JThread();
	virtual ~JThread();
	virtual void Run() = 0;
	static unsigned _stdcall ThreadFun(void* p);
	bool Start();
	void Wait(DWORD timeout = INFINITE);
private:
	HANDLE hThread_;
	unsigned threadId_;
};


#endif _JTHREAD_H_