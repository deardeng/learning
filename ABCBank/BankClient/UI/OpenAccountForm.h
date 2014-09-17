#ifndef _OPEN_ACCOUNT_FORM_H_
#define _OPEN_ACCOUNT_FORM_H_

#include "../JFC/JForm.h"
#include "../JFC/JLable.h"
#include "../JFC/JEdit.h"
#include "../JFC/JButton.h"

#include <string>

using namespace JFC;

namespace UI
{

class OpenAccountForm : public JForm
{
public:
	OpenAccountForm();
	~OpenAccountForm();
	OpenAccountForm(SHORT x, SHORT y, SHORT w, SHORT h,
		const std::string& title);

	virtual void Draw();
	virtual void OnKeyEvent(JEvent* e);

private:
	void DrawBorder();

	void Reset();
	void Submit();

	std::string title_;

	JLable* lblName_;
	JEdit* editName_;
	JLable* lblNameTip_;

	JLable* lblId_;
	JEdit* editId_;
	JLable* lblIdTip_;

	JLable* lblPass_;
	JEdit* editPass_;
	JLable* lblPassTip_;

	JLable* lblPass2_;
	JEdit* editPass2_;
	JLable* lblPass2Tip_;

	JLable* lblMoney_;
	JEdit* editMoney_;
	JLable* lblMoneyTip_;

	JButton* btnSubmit_;
	JButton* btnReset_;
	JButton* btnCancel_;
};

}
#endif // _OPEN_ACCOUNT_FORM_H_