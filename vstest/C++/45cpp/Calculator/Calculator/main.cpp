#include <iostream>
using namespace std;
#include "Parser.h"
#include "Scanner.h"
#include <string>

int main(void){
	STATUS status = STATUS_OK;
	do{
		cout << "> ";
		string buf;
		getline(cin,buf);
		//cout << buf << endl;
		Scanner scanner(buf);
		Parser parser(scanner);
		parser.Parse();
		std::cout << parser.Calculate() << endl;
	}while(status!=STATUS_QUIT);
	return 0;
}