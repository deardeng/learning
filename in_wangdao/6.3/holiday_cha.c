#include <stdio.h>
#include <stdlib.h>
//static int N = 6;
int main()
{
	int i, j, sum = 0;
	//Ê¥µ®Ê÷
	for(i = 1; i <= 5; ++i)
	{
		for(j = 1; j <= 5-i; ++j)
			printf(" ");
		for(j = 5-i+1; j < 5+i; ++j)
		{
			if(i % 2 == 0)
			{
				if(j % 2 == 0)
					printf("*");
				else if(j % 2 == 1)
					printf(" ");
			}
			else if(i % 2 == 1)
			{
				if(j % 2 == 1)
					printf("*");
				else if(j % 2 == 0)
					printf(" ");
			}
		}
		printf("\n");
	}
	for(i = 1; i <= 3; ++i)
	{
		for(j = 1; j <= 4; ++j)
			printf(" ");
		printf("*\n");
	}


	//ËóÐÍ
	for(i = 1; i <= 5; ++i)
	{
		for(j = 1; j <= 9; ++j)
		{
			if((j == i + 4) || (j == 5-i+1))
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

	/*for(i = 1; i <= 5; ++i)
	{
		for(j = 1; j <= 5-i; ++j)
			printf(" ");
		for(j = 5-i; j <= 5+i; ++j)
		{
			if((j = 5-i+1) || (j = 5+i-1))
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}*/
	/*for(i = 1; i <= 4; ++i)
	{
		for(j = 1; j <= 9; ++j)
		{
			if((j = i + 1) || (j = 9 - i))
			{
				printf("*");
			}
			else
				printf(" ");
		}
		printf("\n");
	}*/
	//³Ë·¨¿Ú¾÷
	for(i = 1; i <= 9; ++i)
	{
		for(j = 1; j <= i; ++j)
		{
			sum = i * j;
			printf("%d * %d = %d ", i, j, sum);
		}
		printf("\n");
	}
	return 0;
}

