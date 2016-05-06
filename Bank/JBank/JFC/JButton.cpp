#include "JButton.h"

using namespace JFC;

JButton::JButton()
	:JWindow(0,0,0,0,0)
{
	SetCanFocus();
}
JButton::JButton(SHORT x, SHORT y, SHORT width, SHORT height,
			   	const std::string &text,
				JWindow* parent)
	: JWindow(x, y, width, height, parent),
	  text_(text)
{
	SetCanFocus();
}
JButton::~JButton()
{
}

///绘制
void JButton::Draw()
{
	///如果是当前选中窗口，红底白字，否则灰底蓝字
	if (IsCurrent())
	{
		///关闭光标显示
		jApp->HideCursor();

		SetTextColor(FCOLOR_WHITE);
		SetBkColor(BCOLOR_RED);
	} 
	else
	{
		SetTextColor(FCOLOR_BLUE);
		SetBkColor(BCOLOR_GRAY);
	}

	JRECT rect = {0, 0, Width(), Height()};
	FillRect(rect);
	DrawText(text_);
}