#ifndef _COUNTED_OBJECT_H_
#define _COUNTED_OBJECT_H_

class CountedObject
{
public:
	CountedObject();
	~CountedObject();
public:
	static int GetCount();
private:
	static int count_; //静态成员的引用性声明
};

#endif //_COUNTED_OBJECT_H_