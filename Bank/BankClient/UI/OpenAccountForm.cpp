#include "OpenAccountForm.h"
#include "Validator.h"
#include "FormManager.h"

#include "../JFC/ScreenManager.h"

using namespace JFC;
using namespace UI;

OpenAccountForm::OpenAccountForm(SHORT x, SHORT y, SHORT width, SHORT height,
								 JWindow* parent)
		: BankForm(x, y, width, height, parent)
{
	lblName_ = new JLabel(11, 5, 13, 1, "CUSTOMER NAME:", this);
	editName_ = new JEdit(26, 5, 21, 1, "", this);
	lblNameTip_ = new JLabel(50, 5, 21, 1, "长度3-10位，字母或数字", this);

	lblId_ = new JLabel(13, 8, 12, 1, "IDENTIFY ID:", this);
	editId_ = new JEdit(26, 8, 21, 1, "", this);
	lblIdTip_ = new JLabel(50, 8, 12, 1, "长度18位", this);

	lblPass_ = new JLabel(8, 11, 17, 1, "ACCOUNT PASSWORD:", this);
	editPass_ = new JEdit(26, 11, 21, 1, "", this, EM_PASSWORD);
	lblPassTip_ = new JLabel(50, 11, 11, 1, "长度6-8位", this);

	lblPassRepeat_ = new JLabel(9, 14, 16, 1, "REPEAT PASSWORD:", this);
	editPassRepeat_ = new JEdit(26, 14, 21, 1, "", this, EM_PASSWORD);
	lblPassRepeatTip_ = new JLabel(50, 14, 16, 1, "同上", this);

	lblMoney_ = new JLabel(19, 17, 16, 1, "MONEY:", this);
	editMoney_ = new JEdit(26, 17, 21, 1, "", this);
	lblMoneyTip_ = new JLabel(50, 17, 19, 1, "小数最多两位", this);


	btnSubmit_ = new JButton(5, 20, 10, 3, "SUBMIT", this);
	btnReset_ =	new JButton(50, 20, 10, 3,"RESET", this);
	btnCancel_ = new JButton(65, 20, 10, 3,"CANCEL", this);

	editName_->SetValidator(ValidateName);
	editId_->SetValidator(ValidateId);
	editPass_->SetValidator(ValidatePass);
	editPassRepeat_->SetValidator(ValidatePass);
	editMoney_->SetValidator(ValidateMoney);
}
OpenAccountForm::~OpenAccountForm()
{
	delete lblName_;
	delete editName_;
	delete lblNameTip_;

	delete lblId_;
	delete editId_;
	delete lblIdTip_;

	delete lblPass_;
	delete editPass_;
	delete lblPassTip_;

	delete lblPassRepeat_;
	delete editPassRepeat_;
	delete lblPassRepeatTip_;

	delete lblMoney_;
	delete editMoney_;
	delete lblMoneyTip_;

	delete btnSubmit_;
	delete btnReset_;
	delete btnCancel_;
}
void OpenAccountForm::Draw()
{
	DrawBorder();
	
	SetTextColor(FCOLOR_BLUE);
	SetBkColor(BCOLOR_WHITE);
	JRECT rect = { 1, 1, Width()-2, Height()-2 };
	FillRect(rect);
	
	DrawText(5, 2, "Open Account");
	DrawHLine(3, 2, Width()-3, '-');

	JForm::Draw();

}
void OpenAccountForm::OnKeyEvent(JEvent *e)
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
void OpenAccountForm::Reset()
{
	Init();
	Show();
}
void OpenAccountForm::Submit()
{
	if ( editName_ ->GetText().length() < 3)
	{
		JForm* form = jFormManager.Get( "UserError" );
		jScreenManager.Dump( form, editName_ );
		return ;
	}

	if ( editId_->GetText().length() != 18 )
	{
		JForm* form = jFormManager.Get( "IdError" );
		jScreenManager.Dump( form, editId_ );
		return ;
	}

	if ( editPass_->GetText().length() < 6 )
	{
		JForm* form = jFormManager.Get( "PassError" );
		jScreenManager.Dump( form, editPass_ );
		return ;
	}

	if ( editPassRepeat_->GetText().length() < 6 )
	{
		JForm* form = jFormManager.Get( "PassError" );
		jScreenManager.Dump( form, editPassRepeat_ );
		return ;
	}

	if ( editPass_->GetText() != editPassRepeat_->GetText() )
	{
		JForm* form = jFormManager.Get( "PassRepeatError" );
		jScreenManager.Dump( form, editPassRepeat_ );
		return ;
	}

	if ( editMoney_->GetText().length() == 0 )
	{
		JForm* form = jFormManager.Get( "MoneyError" );
		jScreenManager.Dump( form, editMoney_ );
		return ;
	}
}