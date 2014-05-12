#include <stdio.h>
int f();//C＋＋必须的，C中可有可无
int main()
{
	f();
	return 0;
}
int f()
{
	puts("c function");
	return 0;
}

