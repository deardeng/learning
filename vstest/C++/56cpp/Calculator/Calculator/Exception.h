#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <exception>
#include <string>
class Exception:public std::exception
{
public:
	explicit Exception(const char* message)
		:message_(message){
		FillStackTrace();
	}
	virtual ~Exception()throw(){
	}
	virtual const char* what()const throw();
	const char* StackTrace()const throw();
private:
	void FillStackTrace();
	std::string message_;
	std::string stackTrace_;
};

class SyntaxError:public Exception{
public:
	explicit SyntaxError(const char* message)
		:Exception(message){

	}
	virtual ~SyntaxError()throw(){
	}
};

#endif//_EXCEPTION_H_