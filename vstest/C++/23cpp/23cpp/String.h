#ifndef _STRING_H_
#define _STRING_H_

class String
{
public:
	explicit String(const char* str="");
	String(const String& other);
	String& operator=(const String& other);
	String& operator=(const char* str);
	~String();
	void Display()const;
	bool operator!()const;
private:
	char* AllocAndCpy(const char* str);
	char* str_;
};

#endif //_STRING_H_