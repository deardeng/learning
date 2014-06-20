#ifndef _TELEVISION_H_
#define _TELEVISION_H_

class TeleController;
class Television{
	friend class TeleController;
public:
	Television(int volume,int chanel);
private:
	int volume_;
	int chanel_;
};
#endif //_TELEVISION_H_