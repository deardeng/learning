#include<iostream>
using namespace std;
#include<cstdio>
#include<map>
#include<vector>
int main()
{
	int n,a,b;
	int count1 = 0,count2 = 0;
	map<int ,int> p;
	vector<int> xm;
	vector<int> xy;
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 0;i < n;++i)
		{
			scanf("%d%d",&a,&b);
			p[a] = b;
		}
		vector<int>::iterator iter1;
		xm.push_back(p[1]);	
		iter1 = xm.begin();
		while(p.count(*iter1))
		{
			xm.push_back(p[*iter1]);
			++iter1;
		}
		vector<int>::iterator iter2;
		xy.push_back(p[2]);
		iter2 = xy.begin();
		while(p.count(*iter2))
		{
			xy.push_back(p[*iter2]);
			++iter2;
		}
		iter1 = xm.begin();
		iter2 = xy.begin();
		int flag = 0;
		for(;iter1 != xm.end();++iter1,++count1)
		{
			if(flag)
				break;
			for(;iter2 != xy.end();++iter2,++count2)
			{
				if(*iter1 != *iter2)
				{
					if(count1 == count2)
					{
						printf("%s\n","You are my brother");
						flag = 1;
					}
					else if(count1 > count2)
					{
						printf("%s\n","You are my elder");
						flag = 1;
					}
					else
					{
						printf("%s\n","You are my younger");
						flag = 1;
					}
				}
			}
			count2 = 0;
		}
	}
}