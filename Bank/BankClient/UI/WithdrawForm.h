#ifndef _WITHDRAW_FORM_H_
#define _WITHDRAW_FORM_H_

#include "BankForm.h"

#include "../JFC/JLabel.h"
#include "../JFC/JEdit.h"
#include "../JFC/JButton.h"

#include <string>

namespace UI
{

class WithdrawForm : public BankForm
{
public:
	WithdrawForm(SHORT x, SHORT y, SHORT width, SHORT height, 
		JWindow* parent = jApp->Root());
	~WithdrawForm();

	virtual void Draw();
	virtual void OnKeyEvent(JEvent *e);

private:
	void Reset();
	void Submit();

	JLabel* lblId_;
	JEdit * editId_;
	JLabel* lblIdTip_;
	
	JLabel* lblPass_;
	JEdit * editPass_;
	JLabel* lblPassTip_;

	JLabel* lblMoney_;
	JEdit * editMoney_;
	JLabel* lblMoneyTip_;

	JButton* btnSubmit_;
	JButton* btnReset_;
	JButton* btnCancel_;

};

}

#endif //_WITHDRAW_FORM_H_