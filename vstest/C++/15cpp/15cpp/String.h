#ifndef _STRING_H_
#define _STRING_H_

class String
{
public:
	String(char* str="");
	~String();

	String(const String& other);
	String& operator=(const String& other);

	void Display();

private:
	char* AllocAndCpy(char *str);
	char* str_;
	
};

#endif //_STRING_H_