#include <stdio.h>

int main()
{
	const int n=100;//����ʹ��n��ֵ�ĵط���ֱ����100����
	volatile const int m=200;//m��ʱ���ܸı䣬ÿ�δ��ڴ���ȡ
	int* p = (int*)&n;
	*p = 123;
	p = (int*)&m;
	*p = 456;
	printf("%d, %d\n", n, m);
	return 0;
}

