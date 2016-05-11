#include "ChangePasswordForm.h"
#include "Validator.h"
#include "FormManager.h"

#include "../JFC/ScreenManager.h"

using namespace JFC;
using namespace UI;

ChangePasswordForm::ChangePasswordForm(SHORT x, SHORT y, SHORT width, SHORT height,
									   JWindow* parent)
									   : BankForm(x, y, width, height, parent)
{
	lblId_ = new JLabel(14, 5, 12, 1, "ACCOUNT ID:", this);
	editId_ = new JEdit(26, 5, 21, 1, "", this);
	lblIdTip_ = new JLabel(50, 5, 12, 1, "长度6位 数字", this);

	lblPass_ = new JLabel(8, 8, 18, 1, "ACCOUNT PASSWORD:", this);
	editPass_ = new JEdit(26, 8, 21, 1, "", this, EM_PASSWORD);
	lblPassTip_ = new JLabel(50, 8, 19, 1, "长度6-8位", this);

	lblNewPass_ = new JLabel(12, 11, 14, 1, "NEW PASSWORD:", this);
	editNewPass_ = new JEdit(26, 11, 21, 1, "", this, EM_PASSWORD);
	lblNewPassTip_ = new JLabel(50, 11, 19, 1, "长度6-8位", this);

	lblRepeatPass_ = new JLabel(9, 14, 17, 1, "REPEAT PASSWORD:", this);
	editRepeatPass_ = new JEdit(26, 14, 21, 1, "", this, EM_PASSWORD);
	lblRepeatPassTip_ = new JLabel(50, 14, 19, 1, "长度6-8位", this);


	btnSubmit_ = new JButton(5, 20, 10, 3, "SUBMIT", this);
	btnReset_ =	new JButton(50, 20, 10, 3,"RESET", this);
	btnCancel_ = new JButton(65, 20, 10, 3,"CANCEL", this);


	editId_->SetValidator(ValidateAccountId);
	editPass_->SetValidator(ValidatePass);
	editNewPass_->SetValidator(ValidatePass);
	editRepeatPass_->SetValidator(ValidatePass);

}
ChangePasswordForm::~ChangePasswordForm()
{

	delete lblId_;
	delete editId_;
	delete lblIdTip_;

	delete lblPass_;
	delete editPass_;
	delete lblPassTip_;
	
	delete lblNewPass_;
	delete editNewPass_;
	delete lblNewPassTip_;

	delete lblRepeatPass_;
	delete editRepeatPass_;
	delete lblRepeatPassTip_;


	delete btnSubmit_;
	delete btnReset_;
	delete btnCancel_;
}
void ChangePasswordForm::Draw()
{
	DrawBorder();

	SetTextColor(FCOLOR_BLUE);
	SetBkColor(BCOLOR_WHITE);
	JRECT rect = { 1, 1, Width()-2, Height()-2 };
	FillRect(rect);

	DrawText(5, 2, "Change Password");
	DrawHLine(3, 2, Width()-3, '-');

	JForm::Draw();
}
void ChangePasswordForm::OnKeyEvent(JEvent *e)
{
	JWindow* win = e->GetSender();

	switch( e->GetEventCode() )
	{
	case KEY_ESC:
		Init();
		break;
	case KEY_ENTER:
		if ( win == btnSubmit_ )
		{
			e->Done();
			Submit();
		}
		else if ( win == btnReset_ )
		{
			e->Done();
			Reset();
		}
		else if ( win == btnCancel_ )
		{
			e->Done();
			Init();
			jScreenManager.Restore( this );
		}

		break;
	}

	JForm::OnKeyEvent(e);
}
void ChangePasswordForm::Reset()
{
	Init();
	Show();
}
void ChangePasswordForm::Submit()
{

	if ( editId_->GetText().length() != 6 )
	{
		JForm* form = jFormManager.Get( "AccountIdError" );
		jScreenManager.Dump( form, editId_ );
		return ;
	}
	if ( editPass_->GetText().length() < 6 )
	{
		JForm* form = jFormManager.Get( "PassError" );
		jScreenManager.Dump( form, editPass_ );
		return ;
	}
	if ( editNewPass_->GetText().length() < 6 )
	{
		JForm* form = jFormManager.Get( "PassError" );
		jScreenManager.Dump( form, editNewPass_ );
		return ;
	}
	if ( editRepeatPass_->GetText().length() < 6 )
	{
		JForm* form = jFormManager.Get( "PassError" );
		jScreenManager.Dump( form, editRepeatPass_ );
		return ;
	}
}