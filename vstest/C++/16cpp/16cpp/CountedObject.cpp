#include "CountedObject.h"
int CountedObject::count_=0;//��̬��Ա�Ķ���������

CountedObject::CountedObject(){
	++count_;	
}

CountedObject::~CountedObject(){
	--count_;
}
int CountedObject::GetCount(){
	return count_;
}