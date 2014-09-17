#ifndef _JLABEL_H_
#define _JLABEL_H_

#include "JWindow.h"
#include <string>
namespace JFC{
	class JLable:public JWindow
	{
	public:
		JLable();
		JLable(SHORT x,SHORT y,SHORT width,SHORT height,
			const std::string& text = std::string(),
			JWindow* parent = JApp->Root());
		virtual ~JLable();
		virtual void Draw();
		void SetText(const std::string& text){
			text_ = text;
		}
	private:
		std::string text_;

	};
}
#endif//_JLABEL_H_