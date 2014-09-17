#ifndef _TRANSFER_FORM_H_
#define _TRANSFER_FORM_H_

#include "../JFC/JForm.h"
#include "../JFC/JLable.h"
#include "../JFC/JEdit.h"
#include "../JFC/JButton.h"

#include <string>

using namespace JFC;

namespace UI
{

class TransferForm : public JForm
{
public:
	TransferForm();
	~TransferForm();
	TransferForm(SHORT x, SHORT y, SHORT w, SHORT h,
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

	JLable* lblMoney_;
	JEdit* editMoney_;
	JLable* lblMoneyTip_;

	JLable* lblAccountId2_;
	JEdit* editOtherAccountId_;
	JLable* lblAccountId2Tip_;

	JButton* btnSubmit_;
	JButton* btnReset_;
	JButton* btnCancel_;
};

}

#endif // _TRANSFER_ACCOUNTS_FORM_H_