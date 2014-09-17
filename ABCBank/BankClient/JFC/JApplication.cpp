#include "JApplication.h"
#include "JWindow.h"
#include "JEvent.h"
#include <conio.h>
using namespace JFC;
JApplication* JApplication::self_ = 0;

JApplication::JApplication()
{	
	if(self_){
		return;
	}
	self_ = this;
	SetConsoleOutputCP(936);
	COORD size = {80,25};
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),size);
	HideCursor();
	root_ = new JWindow(0,0,80,25,0);
	root_->Show();
}

JApplication::~JApplication()
{
	delete root_;
}

int JApplication::Exec(){
	while(1){
		//也可以用ReadConsoleInput获得键盘鼠标输入

		int key = _getch();
                                 		if(key == 224){
			key = (224<<8) + _getch();
		}
		else if(key == 0){
			key = -1 * _getch();
		}
		if(current_){
			JEvent e(key,current_);
			current_ ->OnKeyEvent(&e);
		}
	}
	return 0;
}
void JApplication::ShowCursor()const{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);
	cci.bVisible = true;
	SetConsoleCursorInfo(hOut,&cci);
}
void JApplication::HideCursor()const{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);
	cci.bVisible = false;
	SetConsoleCursorInfo(hOut,&cci);
}