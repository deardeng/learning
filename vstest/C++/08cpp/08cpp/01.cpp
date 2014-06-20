#include "Clock.h"

int main(void){
	Clock c;
	c.Init(10,10,10);
	c.Display();
	//c.second_ += 1;
	c.Update();
	c.Display();

	c.SetHour(11);
	c.Display();
	return 0;
}