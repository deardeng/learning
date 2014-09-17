#ifndef _JLINKTEXT_H_
#define _JLINKTEXT_H_

#include "JWindow.h"
#include <string>

namespace JFC{
	class JLinkText:public JWindow
	{
	public:
		JLinkText();
		virtual ~JLinkText();
		JLinkText(SHORT x,SHORT y,SHORT width,SHORT height,
			const std::string& text = std::string(),
			JWindow* parent = JApp->Root());
		virtual void Draw();
	private:
		std::string text_;
	};
}
#endif//_JLINKTEXT_H_