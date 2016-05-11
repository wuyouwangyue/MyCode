#ifndef _TRANSFER_FORM_H_
#define _TRANSFER_FORM_H_

#include "BankForm.h"

#include "../JFC/JLabel.h"
#include "../JFC/JEdit.h"
#include "../JFC/JButton.h"

#include <string>

namespace UI
{

class TransferForm : public BankForm
{
public:
	TransferForm(SHORT x, SHORT y, SHORT width, SHORT height, 
		JWindow* parent = jApp->Root());
	~TransferForm();

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
	
	JLabel* lblToId_;
	JEdit * editToId_;
	JLabel* lblToIdTip_;


	JButton* btnSubmit_;
	JButton* btnReset_;
	JButton* btnCancel_;

};

}

#endif //_TRANSFER_FORM_H_