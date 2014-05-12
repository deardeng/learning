#include<stdio.h>
struct y_m_d{
    int year;
    int month;
    int day;
}date;
int main(){
    int days(struct y_m_d date1);
    printf("input year,month,day:");
    scanf("%d,%d,%d",&date.year,&date.month,&date.day);
    printf("%d/%d is the %dth day in %d.\n",date.month,date.day,days(date),date.year);
}
int days(struct y_m_d date1){
    int sum;
    switch(date1.month){
        case 1:sum=date.day;break;
        case 2:sum=date.day+31;break;
        case 3:sum=date.day+59;break;
        case 4:sum=date.day+90;break;
        case 5:sum=date.day+120;break;
        case 6:sum=date.day+151;break;
        case 7:sum=date.day+181;break;
        case 8:sum=date.day+212;break;
        case 9:sum=date.day+243;break;
        case 10:sum=date.day+273;break;
        case 11:sum=date.day+304;break;
        case 12:sum=date.day+334;break;
    }
    if((date.year%4==0&&date.year%100!=0||date.year%400==0)&&date.month>=3)sum+=1;
    return sum;
}
