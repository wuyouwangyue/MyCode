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
	///���Խ��ս���
	SetCanFocus();
}
JLinkText::~JLinkText()
{
}
void JLinkText::Draw()
{
	///����ǽ��㣬���ƴ��»��ߴ���ͷ
	if ( IsCurrent() )
	{
		SetTextColor(FCOLOR_RED | COMMON_LVB_UNDERSCORE);
		jApp->HideCursor();
		DrawText(0, 0, "-> " + text_);
	} 
	else
	{
		SetTextColor(FCOLOR_BLUE);
		///�������м�ͷʱ��һ���ĳ��ȣ��ں�����������ո�
		DrawText(0, 0, text_ + "   ");
	}
}
