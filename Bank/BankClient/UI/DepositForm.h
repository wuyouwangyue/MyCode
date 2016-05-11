#ifndef _DEPOSIT_FORM_H_
#define _DEPOSIT_FORM_H_

#include "BankForm.h"

#include "../JFC/JLabel.h"
#include "../JFC/JEdit.h"
#include "../JFC/JButton.h"

#include <string>

namespace UI
{

class DepositForm : public BankForm
{
public:
	DepositForm(SHORT x, SHORT y, SHORT width, SHORT height, 
		JWindow* parent = jApp->Root());
	~DepositForm();

	virtual void Draw();
	virtual void OnKeyEvent(JEvent *e);

private:
	void Reset();
	void Submit();

	JLabel* lblId_;
	JEdit * editId_;
	JLabel* lblIdTip_;

	JLabel* lblMoney_;
	JEdit * editMoney_;
	JLabel* lblMoneyTip_;

	JButton* btnSubmit_;
	JButton* btnReset_;
	JButton* btnCancel_;

};

}

#endif //_DEPOSIT_FORM_H_