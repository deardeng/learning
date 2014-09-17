#ifndef _JMESSAGEBOX_H_
#define _JMESSAGEBOX_H_

#include "JWindow.h"
#include <string>
#include <vector>

namespace JFC{
	class JMessageBox
	{
	public:
		static int Show(const std::string& title,const std::string& text,std::vector<std::string>& buttons);
	};
	class JMessageBoxImpl:public JWindow{
	public:
		JMessageBoxImpl(SHORT x,SHORT y,SHORT width,SHORT height,
			const std::string& title,const std::string& text,
			std::vector<std::string>&buttons,SHORT btn_distance,
			int lines,JWindow* parent = JApp->Root());
		~JMessageBoxImpl(){}
		virtual void Draw();
		int Exec();
	private:
		std::string title_;
		std::string text_;
		short btnDistance_;
		int lines_;
	};
}
#endif//_JMESSAGEBOX_H_