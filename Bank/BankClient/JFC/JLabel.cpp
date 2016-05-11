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
	{///颜色设置成与父窗口相同的颜色
		SetBkColor(GetParent()->GetBkColor());
	}
	else
		SetBkColor(BCOLOR_WHITE);
	
	///用背景色先清除区域
	JRECT rect = {0, 0, Width(), Height()};
	FillRect(rect);
	///从左边开始填充文字
	DrawText(0, 0, text_);
}

JLabel::~JLabel()
{
}
