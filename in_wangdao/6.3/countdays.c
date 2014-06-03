#include<stdio.h>

int days_per_month[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int is_bad_year(int n);

int countday(int year,int month,int day);

int redays(int year,int month,int day);

int diffdays(int day1,int day2){
    return day1>day2?(day1-day2):(day2-day1);
}

int whichday(int year,int month,int day){
    int wday=redays(year,month,day);
    int stdday=redays(1900,1,1);
    int cday=diffdays(stdday,wday);
    return (1+cday)%7;
}

int main(){
    int year,month,day;
    printf("please input the data you want to know (xxxx.xx.xx) :");
    scanf("%d.%d.%d",&year,&month,&day);
    printf("the day is %4d.%02d.%02d ?\n",year,month,day);
    printf("the day is that year %dth days.\n",countday(year,month,day));
    printf("the day is %dth in a week.\n",whichday(year,month,day));
    int day1,day2;
    printf("two date (xxxx.xx.xx):\n");
    printf("date1:");
    scanf("%d.%d.%d",&year,&month,&day);
    day1=redays(year,month,day);
    printf("date2:");
    scanf("%d.%d.%d",&year,&month,&day);
    day2=redays(year,month,day);
    printf("the date1-date2 has %d days.\n",diffdays(day1,day2));
}

int countday(int year,int month,int day){
    int i,days=0;
    if(is_bad_year(year)){
        for(i=0;i<month-1;i++)
            days+=days_per_month[i];
        if(month>2)
            days++;
        days+=day;
    }
    else{
        for(i=0;i<month-1;i++)
            days+=(days_per_month[i]);
        days+=day;
    }
    return days;
}

int is_bad_year(int n){
    return (n%4==0&&!(n%100==0))||(n%400==0);
}

int redays(int year,int month,int day){
    int dyear,days;
    dyear=year-1900;
    int i,countbadyear=0;
    for(i=1900;i<year;i++)
        if(is_bad_year(i))
            countbadyear++;
    days=countbadyear*366+(dyear-countbadyear)*365+countday(year,month,day);
    return days;
}
