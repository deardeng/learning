#ifndef _JBUTTON_H_
#define _JBUTTON_H_
#include "JWindow.h"
#include <string>

namespace JFC{
	class JButton:public JWindow
	{
	public:
		JButton();
		JButton(SHORT x,SHORT y,SHORT width,SHORT height,const std::string& text = std::string(),JWindow* parent = JApp->Root());
		virtual ~JButton();
		void Draw();
	private:
		std::string text_;
	};
}
#endif //_JBUTTON_H_