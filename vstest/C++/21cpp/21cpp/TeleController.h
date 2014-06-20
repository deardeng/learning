#ifndef _TELECONTROLLER_H_
#define  _TELECONTROLLER_H_
//#include "Television.h"
class Television;
class TeleController{
public:
	void VolumeUp(Television& tv);
	void VolumeDown(Television& tv);
	void ChanelUp(Television& tv);
	void ChanelDown(Television& tv);
};
#endif// _TELECONTROLLER_H_