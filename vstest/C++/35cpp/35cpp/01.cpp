#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Shape{
public:
	virtual void Draw()=0;
	/*void Draw(){
		cout << "Square::Draw()..." << endl;
	}*/
	virtual ~Shape(){
		cout << "~Shape()..." << endl;
	}
};
class Circle:public Shape{
public:
	void Draw(){
		cout << "Circle::Draw()..." << endl;
	}
	~Circle(){
		cout << "~Circle..." << endl;
	}
};
class Square:public Shape{
public:
	void Draw(){
		cout << "Square::Draw()..." << endl;
	}
	~Square(){
		cout << "~Square..." << endl;
	}
};
class Rectangle:public Shape{
public:
	void Draw(){
		cout << "Rectangle::Draw()..." << endl;
	}
	~Rectangle(){
		cout << "~Rectangle..." << endl;
	}
};
//动态创建
//简单工厂模式
class ShapeFactory{
public:
	static Shape* CreateShape(const string& name){
		Shape* ps=0;
		if(name=="Circle"){
			ps = new Circle;
		}
		else if(name == "Square"){
			ps = new Square;
		}
		else if(name == "Rectangle"){
			ps = new Rectangle;
		}
		return ps;
	}
};
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
	//Shape s;		//Error,不能实例化抽象类
	vector<Shape*> v;
	Shape *ps;
	/*ps=new Circle;
	v.push_back(ps);
	ps=new Square;
	v.push_back(ps);
	ps = new Rectangle();
	v.push_back(ps);*/

	ps = ShapeFactory::CreateShape("Circle");
	v.push_back(ps);
	ps = ShapeFactory::CreateShape("Square");
	v.push_back(ps);
	ps = ShapeFactory::CreateShape("Rectangle");
	v.push_back(ps);

	DrawAllShapes(v);
	deleteAllShapes(v);

	return 0;
}