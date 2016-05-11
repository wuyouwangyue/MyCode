#ifndef _CHANGEPASSWORD_FORM_H_
#define _CHANGEPASSWORD_FORM_H_

#include "BankForm.h"

#include "../JFC/JLabel.h"
#include "../JFC/JEdit.h"
#include "../JFC/JButton.h"

#include <string>

namespace UI
{

class ChangePasswordForm : public BankForm
{
public:
	ChangePasswordForm(SHORT x, SHORT y, SHORT width, SHORT height, 
		JWindow* parent = jApp->Root());
	~ChangePasswordForm();

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
	
	JLabel* lblNewPass_;
	JEdit * editNewPass_;
	JLabel* lblNewPassTip_;
	
	JLabel* lblRepeatPass_;
	JEdit * editRepeatPass_;
	JLabel* lblRepeatPassTip_;

	JButton* btnSubmit_;
	JButton* btnReset_;
	JButton* btnCancel_;

};

}

#endif //_CHANGEPASSWORD_FORM_H_