#include "Shape.h"
#include "DynBase.h"
#include <iostream>
using namespace std;

void Circle::Draw(){
	cout << "Circle::Draw()..." << endl;
}
Circle::~Circle(){
	cout << "~Circle()..." << endl;
}

void Square::Draw(){
	cout << "Square::Draw()..." << endl;
}
Square::~Square(){
	cout << "~Square..." << endl;
}

void Rectangle::Draw(){
	cout << "Rectangle::Draw()..." << endl;
}
Rectangle::~Rectangle(){
	cout << "~Rectangle..." << endl;
}

REGISTER_CLASS(Circle);
REGISTER_CLASS(Square);
REGISTER_CLASS(Rectangle);


//class class_nameCircle{
//public:
//	static void* NewInstance(){
//		return new Circle;
//	}
//private:
//	static Register reg_;
//};
//Register class_nameCircle::reg_("Circle",class_nameCircle::NewInstance)
//
//#define  REGISTER_CLASS(class_name) \
//class class_name##Register{			\
//public:								\
//	static void* NewInstance(){		\
//	return new class_name;			\
//}									\
//private:							\
//	static Register reg_;			\
//};									\
//Register class_name##Register::reg_(#class_name,class_name##Register::NewInstance)
