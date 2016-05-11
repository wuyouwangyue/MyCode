#include "LoginForm.h"
#include "Validator.h"
#include "FormManager.h"

#include "../JFC/JEvent.h"
#include "../JFC/JMessageBox.h"
#include "../JFC/ScreenSaver.h"
#include "../JFC/ScreenManager.h"

using namespace JFC;
using namespace UI;


LoginForm::LoginForm(SHORT x, SHORT y, SHORT width, SHORT height,
		  JWindow* parent)
	: BankForm(x, y, width, height, parent)
{


	lblUser_ = new JLabel(16, 8, 9, 1, "USERNAME:", this);
	editUser_ = new JEdit(26, 8, 21, 1, "", this);
	editUser_->SetValidator(ValidateName);
	lblUserTip_ = new JLabel(50, 8, 22, 1, "长度3-18位，字母或数字", this);


	lblPass_ = new JLabel(16, 12, 9, 1, "PASSWORD:", this);
	editPass_ = new JEdit(26, 12, 21, 1, "", this, EM_PASSWORD);
	editPass_->SetValidator(ValidatePass);
	lblPassTip_ = new JLabel(50, 12, 9, 1, "长度6-8位", this);

	btnLogin_ = new JButton(22, 17, 11, 3, "LOGIN", this);
	btnExit_ = new JButton(48, 17, 11, 3, "EXIT", this);
}
LoginForm::~LoginForm()
{
	delete lblUser_;
	delete lblPass_;
	delete lblUserTip_;
	delete lblPassTip_;

	delete btnLogin_;
	delete btnExit_;

	delete editUser_;
	delete editPass_;
}

void LoginForm::Draw()
{
	DrawBorder();

	SetTextColor(FCOLOR_BLUE);
	SetBkColor(BCOLOR_WHITE);
	
	///欢迎标语
	DrawText(28, 3, "Login To The Bank System");
	DrawHLine(4, 25, 54, '-');
	
	///版权标语
	DrawText(2, Height()-2, "Author: http://www.cnblogs.com/liuxin13/");

	JForm::Draw();
}
void LoginForm::OnKeyEvent(JEvent *e)
{
	JWindow* win = e->GetSender();
	int key = e->GetEventCode();

	if ( win == btnLogin_ && key == KEY_ENTER)
	{
		Login();
		e->Done();
	}
	else if ( (win == btnExit_ && key == KEY_ENTER) || key == KEY_ESC )
	{
		Exit();
		e->Done();
	}
	else if ( win == editPass_ && key == KEY_ENTER )
	{
		Login();
		e->Done();
	}

	JForm::OnKeyEvent(e);
}
void LoginForm::Login()
{
	///登录账号小于三位
	if ( editUser_->GetText().length() < 3 )
	{
		JForm *form = jFormManager.Get( "UserError" );

		jScreenManager.Dump( form, editUser_ );

		return ;
	}
	///登录密码小于6位
	if ( editPass_->GetText().length() < 6 )
	{
		JForm* form = jFormManager.Find( "PassError" );

		jScreenManager.Dump( form, editPass_ );

		return ;
	}

	// TODO ... 登录操作
	JForm* form = jFormManager.Find("MainMenuForm");
	jScreenManager.Dump(form);
}

void LoginForm::Exit()
{
	JForm* form = jFormManager.Find( "ExitMessage" );

	jScreenManager.Dump(form);
	int res = form->Exec();

	if ( res == -1 || res == 1 )
		jScreenManager.Restore(form);
	else
	{
		jScreenManager.Restore(this);
		exit(1);
	}
}