#ifndef _SCANNER_H_
#define _SCANNER_H_ 
#include <string>
class Scanner
{
public:
	Scanner(const std::string& buf);
private:
	const std::string buf_;
};

#endif //_SCANNER_H_