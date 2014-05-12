#include<stdio.h>
int main()
{
	int sum_day(int month,int day);
	int leap(int year);
	int year,month,day,days;
	printf("input data(year,month,day):");
	scanf("%d,%d,%d",&year,&month,&day);
	printf("%d/%d/%d",year,month,day);
	days=sum_day(month,day);
	if(leap(year)&&month>=3)
		days = days + 1;
	printf("is the %dth day in this year.\n",days);
	return 0;
}

int sum_day(int month,int day){
	int day_tab[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int i;
	for(i=1;i<month;i++)
		day+=day_tab[i];
	return day;
}

int leap(int year){
	return year%4==0&&year%100!=0||year%400==0;
}