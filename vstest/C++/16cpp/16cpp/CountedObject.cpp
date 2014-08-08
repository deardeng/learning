#include "CountedObject.h"
int CountedObject::count_=0;//静态成员的定义性声明

CountedObject::CountedObject(){
	++count_;	
}

CountedObject::~CountedObject(){
	--count_;
}
int CountedObject::GetCount(){
	return count_;
}