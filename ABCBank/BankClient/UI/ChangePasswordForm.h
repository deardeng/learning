#ifndef _CHANGE_PASSWORD_FORM_H_
#define _CHANGE_PASSWORD_FORM_H_

#include "../JFC/JForm.h"
#include "../JFC/JLable.h"
#include "../JFC/JEdit.h"
#include "../JFC/JButton.h"
#include <string>

using namespace JFC;
namespace UI{
	class ChangePasswordForm : public JForm
	{
	public:
		ChangePasswordForm();
		~ChangePasswordForm();
		ChangePasswordForm(SHORT x,SHORT y,SHORT w,SHORT h,
			const std::string& title);
		virtual void Draw();
		virtual void OnKeyEvent(JEvent* e);
		
	private:
		void DrawBorder();
		void Reset();
		void Submit();

		std::string title_;
		
		JLable* lblAccountId_;
		JEdit* editAccountId_;
		JLable* lblAccountIdTip_;

		JLable* lblPass_;
		JEdit* editPass_;
		JLable* lblPassTip_;

		JLable* lblNewPass_;
		JEdit* editNewPass_;
		JLable* lblNewPassTip_;

		JLable* lblNewPass2_;
		JEdit* editNewPass2_;
		JLable* lblNewPass2Tip_;
		

		JButton* btnSubmit_;
		JButton* btnReset_;
		JButton* btnCancel_;
	};
}
#endif //_CHANGE_PASSWORD_FORM_H_