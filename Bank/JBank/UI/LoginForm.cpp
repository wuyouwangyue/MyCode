#include "LoginForm.h"
#include "Validator.h"

#include "../JFC/JEvent.h"

using namespace UI;

LoginForm::LoginForm()
{
}

LoginForm::LoginForm(SHORT x, SHORT y, SHORT width, SHORT height,
		  JWindow* parent)
	: JForm(x, y, width, height, parent)
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
///绘制边界
void LoginForm::DrawBorder()
{
	SetTextColor(FCOLOR_YELLO);
	SetBkColor(BCOLOR_RED);
	
	///上下边界
	DrawHLine(0, 0, Width()-1, '-');
	DrawHLine(Height()-1, 0, Width()-1, '-');

	///左右边界
	DrawVLine(0, 1, Height()-2, ' ');
	DrawVLine(Width()-1, 1, Height()-2, ' ');
}
void LoginForm::OnKeyEvent(JEvent *e)
{
	JWindow* win = e->GetSender();

	///button按钮先不处理回车键
	if ((win == btnLogin_ || win == btnExit_) && e->GetEventCode() == KEY_ENTER)
		e->Done();

	JForm::OnKeyEvent(e);
}