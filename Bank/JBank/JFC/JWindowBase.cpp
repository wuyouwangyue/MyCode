#include "JWindowBase.h"
#include <algorithm>

using namespace JFC;

ScreenBuffer* JWindowBase::sb_ = new ScreenBuffer;

JWindowBase::JWindowBase()
	: x_(0), y_(0), width_(0), height_(0)
{
}
JWindowBase::JWindowBase(SHORT x, SHORT y, SHORT width, SHORT height)
	: x_(x),
	  y_(y),
	  width_(width),
	  height_(height),
	  fColor_(FCOLOR_BLACK),
	  bColor_(BCOLOR_WHITE)
{

}
JWindowBase::~JWindowBase()
{
}
///���ù��λ��
void JWindowBase::SetCursorPos(SHORT x, SHORT y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
///����ˢ��
void JWindowBase::Refresh()
{
	sb_->refresh(x_, y_, width_, height_);
}
///�����������
void JWindowBase::FillRect(JRECT rect)
{
	for (SHORT i=rect.Top; i<rect.Bottom; ++i)
	{
		DrawHLine(i, rect.Left, rect.Right, ' ');
	}
}
///�����ı�, ����x, y����ڱ����ڵ�λ�ã�
void JWindowBase::DrawText(SHORT x, SHORT y, std::string& text)
{
	sb_->write(x_+x, y_+y, text, fColor_, bColor_);
}
///Ĭ�����м����
void JWindowBase::DrawText(std::string& text)
{
	SHORT x = (Width() - text.length()) / 2;
	SHORT y = (Height()-1) / 2;

	DrawText(x, y, text);
}
///����ˮƽ��
void JWindowBase::DrawHLine(SHORT x, SHORT y1, SHORT y2, char ch)
{
	if(y1 > y2)
		std::swap(y1, y2);

	size_t count = y2 - y1;

	std::string str(count, ch);
	DrawText(x, y1, str);
}
///���ƴ�ֱ��
void JWindowBase::DrawVLine(SHORT y, SHORT x1, SHORT x2, char ch)
{
	if(x1 > x2)
		std::swap(x1, x2);
	std::string str;
	str += ch;

	for(SHORT i = x1; i<=x2; i++)
	{
		DrawText(i, y, str);
	}

}
///�������
void JWindowBase::ClearWindow()
{
	JRECT rect = {0, 0, Width(), Height()};
	FillRect(rect);
}