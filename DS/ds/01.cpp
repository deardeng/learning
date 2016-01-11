#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int *p;
	p = (int*)malloc(sizeof(int)* 1024);
	printf("paddr=%p\n", p);
	if (p == NULL)
	{
		printf("malloc error");
		return 1;
	}
	int i = 10000 - 1;
	for (int *pA = p; pA < p + 1024; ++pA)
	{
		*pA = rand() % 9000 + 1000;
		//*pA = i;
		//--i;
	}
	int *pMax;
	int *pMin;
	pMax = (int*)malloc(sizeof(int));
	pMin = (int*)malloc(sizeof(int));

	int *ppMax;
	int *ppMin;

	ppMax = pMax;
	ppMin = pMin;

	*pMax = 1000;
	*pMin = 10000;

	for (int *pA = p; pA < p + 1024; ++pA)
	{
		if (*pA > *pMax)
		{
			ppMax = pA;
			*pMax = *pA;
		}
		if (*pA < *pMin)
		{
			ppMin = pA;
			*pMin = *pA;
		}
	}
	printf("max = %d\nppmax = %x\nppmax-p = %d\n*ppmax = %d\n", *pMax, ppMax, ppMax - p, *ppMax);
	printf("min = %d\nppmin = %p\nppmin-p = %d\n", *pMin, *ppMin, ppMin- p);
}