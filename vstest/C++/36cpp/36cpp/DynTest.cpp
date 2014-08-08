#include "Shape.h"
#include "DynBase.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


void DrawAllShapes(const vector<Shape*>& v){
	vector<Shape*>::const_iterator it;
	for(it=v.begin();it!=v.end();++it){
		(*it)->Draw();
	}
	cout << endl;
}

void deleteAllShapes(const vector<Shape*>& v){
	vector<Shape*>::const_iterator it;
	for(it=v.begin();it!=v.end();++it){
		delete (*it);
	}
}

int main(void){

	vector<Shape*> v;
	Shape *ps;


	ps = static_cast<Shape*>(DynObjectFactory::CreateObject("Circle"));
	v.push_back(ps);
	ps = static_cast<Shape*>(DynObjectFactory::CreateObject("Square"));
	v.push_back(ps);
	ps = static_cast<Shape*>(DynObjectFactory::CreateObject("Rectangle"));
	v.push_back(ps);

	DrawAllShapes(v);
	deleteAllShapes(v);

	return 0;
}