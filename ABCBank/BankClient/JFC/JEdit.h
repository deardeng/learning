#ifndef _JEDIT_H_
#define _JEDIT_H_

#include "JWindow.h"
#include <string>

namespace JFC{
	class JEvent;
	typedef bool(*VALIDATOR)(const std::string& str,char ch);
	static bool DefaultValidator(const std::string& str,char ch){
		return true;
	}
	class JEdit:public JWindow
	{
	public:
		enum EchoMode{
			EM_NORMAL,
			EM_PASSWORD
		};
		JEdit();
		JEdit(SHORT x,SHORT y,SHORT width,SHORT height,
			const std::string& text = std::string(),
			JWindow* parent = JApp->Root(),
			EchoMode mode = JEdit::EM_NORMAL,
			VALIDATOR validator = DefaultValidator);
		virtual ~JEdit();
		virtual void Draw();
		virtual void OnKeyEvent(JEvent* e);
		const std::string& GetText()const{
			return text_;
		}
		void SetText(const std::string& text){
			text_ = text;
			currIndex_ = static_cast<int>(text_.length());
		}
		void SetValidator(VALIDATOR validator){
			validator_ = validator;
		}
	private:
		std::string text_;
		int currIndex_;
		EchoMode mode_;
		VALIDATOR validator_;
	};
}
#endif//_JEDIT_H_