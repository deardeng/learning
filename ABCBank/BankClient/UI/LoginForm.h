#ifndef _LOGIN_FORM_H_
#define _LOGIN_FORM_H_

#include "../JFC/JButton.h"
#include "../JFC/JForm.h"
#include "../JFC/JLable.h"
#include "../JFC/JEdit.h"

using namespace JFC;
namespace UI{
	//class JFC::JButton;
	class LoginForm:public JForm{
	public:
		LoginForm(SHORT x,SHORT y,SHORT width,SHORT height,
			JWindow* parent = JApp->Root());
		~LoginForm();
		virtual void Draw();
		virtual void OnKeyEvent(JEvent* e);
		
	private:
		void Reset();
		void Login();
		void Exit();
		void DrawBorder();


		JEdit* editUser_;
		JLable* lblUser_;
		JLable* lblUserTip_;

		JEdit* editPass_;
		JLable* lblPass_;
		JLable* lblPassTip_;

		JButton* btnLogin_;
		JButton* btnExit_;
	};
	
}
#endif//_LOGIN_FORM_H_