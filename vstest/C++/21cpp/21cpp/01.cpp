#include <iostream>
using namespace std;
#include <math.h>
class Point{
	
public:
	Point(int x,int y);
	friend double Distance(const Point &p1,const Point &p2);
private:
	
	int x_;
	int y_;
};
Point::Point(int x,int y):x_(x),y_(y){}
double Distance(const Point &p1,const Point &p2){
	double dx=p1.x_-p2.x_;
	double dy=p1.y_-p2.y_;
	return sqrt(dx*dx+dy*dy);

}
int main(void){
	Point p1(3,4);
	Point p2(6,9);
	cout << Distance(p1,p2) << endl;
	return 0;
}