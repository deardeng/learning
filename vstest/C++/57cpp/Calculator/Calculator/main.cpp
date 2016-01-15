#include <iostream>
using namespace std;
#include "Parser.h"
#include "Scanner.h"
#include <string>
#include "Exception.h"
#include "Calc.h"
int main(void){
	Calc calc;
	STATUS status = STATUS_OK;
	do{
		cout << "> ";
		string buf;
		getline(cin,buf);
		//cout << buf << endl;
		Scanner scanner(buf);
		if(!scanner.IsEmpty()){
			Parser parser(scanner,calc);
			try{
				status=parser.Parse();
				if(status==STATUS_OK){
					std::cout << parser.Calculate() << endl;
				}
				
			}
			catch(SyntaxError& se){
				status=STATUS_QUIT;
				std::cout << se.what() << std::endl;
				std::cout << se.StackTrace() << std::endl;
			}
			catch(Exception& e){
				status=STATUS_QUIT;
				std::cout << e.what() << std::endl;
			}
			catch(std::bad_alloc& e){
				status=STATUS_QUIT;
				std::cout << e.what() << std::endl;
			}
			catch(...){
				status=STATUS_QUIT;
				std::cout << "Internal error." << std::endl;
			}
			
			
		}
		else{
			std::cout << "Expression is empty." << std::endl;
			status=STATUS_QUIT;
		}
	}while(status!=STATUS_QUIT);
	return 0;
}