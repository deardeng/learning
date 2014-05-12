#include <stdio.h>

int main()
{
	const int n=100;//后面使用n的值的地方会直接用100代替
	volatile const int m=200;//m随时可能改变，每次从内存重取
	int* p = (int*)&n;
	*p = 123;
	p = (int*)&m;
	*p = 456;
	printf("%d, %d\n", n, m);
	return 0;
}

