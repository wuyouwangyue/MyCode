#include "LoginForm.h"

using namespace UI;

LoginForm::LoginForm()
{
}

LoginForm::LoginForm(SHORT x, SHORT y, SHORT width, SHORT height,
		  JWindow* parent)
	: JForm(x, y, width, height, parent)
{
	btnLogin_ = new JButton(22, 17, 11, 3, "LOGIN", this);
	btnExit_ = new JButton(48, 17, 11, 3, "EXIT", this);
}
LoginForm::~LoginForm()
{
}

void LoginForm::Draw()
{
	DrawBorder();

	SetTextColor(FCOLOR_BLUE);
	SetBkColor(BCOLOR_WHITE);
	
	///��ӭ����
	DrawText(28, 3, "Login To The Bank System");
	DrawHLine(4, 25, 54, '-');
	
	///��Ȩ����
	DrawText(2, Height()-2, "Author: http://www.cnblogs.com/liuxin13/");

	JForm::Draw();
}
///���Ʊ߽�
void LoginForm::DrawBorder()
{
	SetTextColor(FCOLOR_YELLO);
	SetBkColor(BCOLOR_RED);
	
	///���±߽�
	DrawHLine(0, 0, Width()-1, '-');
	DrawHLine(Height()-1, 0, Width()-1, '-');

	///���ұ߽�
	DrawVLine(0, 1, Height()-2, ' ');
	DrawVLine(Width()-1, 1, Height()-2, ' ');
}