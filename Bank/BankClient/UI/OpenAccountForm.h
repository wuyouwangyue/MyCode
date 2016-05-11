#ifndef _OPEN_ACCOUNT_FORM_H_
#define _OPEN_ACCOUNT_FORM_H_

#include "BankForm.h"

#include "../JFC/JLabel.h"
#include "../JFC/JEdit.h"
#include "../JFC/JButton.h"

#include <string>

namespace UI
{

class OpenAccountForm : public BankForm
{
public:
	OpenAccountForm(SHORT x, SHORT y, SHORT width, SHORT height, 
					JWindow* parent = jApp->Root());
	~OpenAccountForm();

	virtual void Draw();
	virtual void OnKeyEvent(JEvent *e);

private:
	void Reset();
	void Submit();

	JLabel* lblName_;
	JEdit * editName_;
	JLabel* lblNameTip_;

	JLabel* lblId_;
	JEdit * editId_;
	JLabel* lblIdTip_;

	JLabel* lblPass_;
	JEdit * editPass_;
	JLabel* lblPassTip_;

	JLabel* lblPassRepeat_;
	JEdit * editPassRepeat_;
	JLabel* lblPassRepeatTip_;

	JLabel* lblMoney_;
	JEdit * editMoney_;
	JLabel* lblMoneyTip_;

	JButton* btnSubmit_;
	JButton* btnReset_;
	JButton* btnCancel_;

};

}

#endif //_OPEN_ACCOUNT_FORM_H_