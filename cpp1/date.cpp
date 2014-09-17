#include<iostream>
using namespace std;
struct Date{
    int y;//year
    int m;//month
    int d;//day
};
bool isLeap(int y){
    return y%4==0&&y%100!=0||y%400==0;
}
int daysOfMonth(int y,int m){
    int day[12]={31,0,31,30,31,30,31,31,30,31,30,31};
    if(m!=2)
        return day[m-1];
    else return 28+isLeap(y);
}
int daysOfDate(Date d){
    int days=0;
    for(int y=1;y<d.y;y++)
        days += 365+isLeap(y);
    for(int m=1;m<d.m;m++)
        days += daysOfMonth(d.y,m);
    days += d.d;
    return days;
}

int main(){
    Date d1,d2;
    cout << "input 2 dates(YYYY MM DD):";
    cin >> d1.y >> d1.m >> d1.d;
    cin >> d2.y >> d2.m >> d2.d;
    int days1=daysOfDate(d1);
    int days2=daysOfDate(d2);
    cout << "difference:" << days2-days1 << endl;
    cout << "weekday:" << days1%7 << ' ' << days2%7 << endl;
    return 0;
}