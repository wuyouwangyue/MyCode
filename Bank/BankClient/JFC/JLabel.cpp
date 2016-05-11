#include "JLabel.h"

using namespace JFC;

JLabel::JLabel()
{
}

JLabel::JLabel(SHORT x, SHORT y, SHORT width, SHORT height,
			   const std::string &text,JWindow* parent)
   : JWindow(x, y, width, height, parent),
     text_(text)
{

}

void JLabel::Draw()
{
	SetTextColor(FCOLOR_BLUE);
	if (GetParent())
	{///��ɫ���ó��븸������ͬ����ɫ
		SetBkColor(GetParent()->GetBkColor());
	}
	else
		SetBkColor(BCOLOR_WHITE);
	
	///�ñ���ɫ���������
	JRECT rect = {0, 0, Width(), Height()};
	FillRect(rect);
	///����߿�ʼ�������
	DrawText(0, 0, text_);
}

JLabel::~JLabel()
{
}
