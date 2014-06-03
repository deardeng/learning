#include <stdio.h>
static int N = 6;
void fun(int n)
{
	int i = 0;
	if (n == 1)
		printf("%*c*\n", N - n + 1, 0);
	else
	{
		fun(n - 1);
		if (n != N)
			printf("%*c", N - n + 1, 0);
		while (i < n)
		{
			printf("* ");
			++i;
		}
		printf("\n");
	}
}
int main(void)
{
	int n = N;
	int i;
	fun(n);
	for (i = 0; i < n; i++)
		printf("%*c*\n", n , 0);
	return 0;
}
