#ifndef _SHAPE_H_
#define _SHAPE_H_

class Shape{
public:
	virtual void Draw()=0;
	virtual ~Shape(){};
};
class Circle:public Shape{
public:
	void Draw();
	~Circle();
};
class Square:public Shape{
public:
	void Draw();
	~Square();
};
class Rectangle:public Shape{
public:
	void Draw();
	~Rectangle();
};

#endif // _SHAPE_H_