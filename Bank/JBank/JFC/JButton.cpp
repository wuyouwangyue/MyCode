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

///����
void JButton::Draw()
{
	///����ǵ�ǰѡ�д��ڣ���װ��֣�����ҵ�����
	if (IsCurrent())
	{
		///�رչ����ʾ
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