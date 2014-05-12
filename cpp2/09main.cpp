#include "09time.h"
int main()
{
	Time t1;
	Time t2(17,4,59);
	t1.tick();
	t2.tick();
	t1.show();
	t2.show();
	return 0;
}

