#include "JLinkText.h"

using namespace JFC;

JLinkText::JLinkText()
	: JWindow(0, 0, 0, 0, 0), 
	  text_(std::string())
{
	SetCanFocus();
}
JLinkText::JLinkText(SHORT x, SHORT y, SHORT width, SHORT height,
					  const std::string& text,
					  JWindow* parent)
		: JWindow(x, y, width, height, parent), text_(text)
{
	///可以接收焦点
	SetCanFocus();
}
JLinkText::~JLinkText()
{
}
void JLinkText::Draw()
{
	///如果是焦点，绘制带下划线带箭头
	if ( IsCurrent() )
	{
		SetTextColor(FCOLOR_RED | COMMON_LVB_UNDERSCORE);
		jApp->HideCursor();
		DrawText(0, 0, "-> " + text_);
	} 
	else
	{
		SetTextColor(FCOLOR_BLUE);
		///保持与有箭头时候一样的长度，在后面添加三个空格
		DrawText(0, 0, text_ + "   ");
	}
}
