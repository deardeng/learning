#include <iostream>
using namespace std;
#include "Parser.h"
#include "Scanner.h"
#include <string>

int main(void){
	do{
		cout << "> ";
		string buf;
		getline(cin,buf);
		cout << buf << endl;
		Scanner scanner(buf);
		Parser parser(scanner);
		parser.Parse();
		parser.Calculate();
	}while(1);
	return 0;
}