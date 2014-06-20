#include <iostream>
using namespace std;
#include "TeleController.h"
#include "Television.h"

//class Television{
//	friend class TeleController;
//public:
//	Television(int volume,int chanel):volume_(volume),chanel_(chanel){}
//private:
//	int volume_;
//	int chanel_;
//};
//class TeleController{
//public:
//	void VolumeUp(Television& tv){
//		tv.volume_+=1;
//	}
//	void VolumeDown(Television& tv){
//		tv.volume_-=1;
//	}
//	void ChanelUp(Television& tv){
//		tv.chanel_+=1;
//	}
//	void ChanelDown(Television& tv){
//		tv.chanel_+=1;
//	}
//};
int main(void){
	Television tv(1,1);
	TeleController tc;
	tc.VolumeUp(tv);
	return 0;
}