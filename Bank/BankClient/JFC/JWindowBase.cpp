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
///设置光标位置
void JWindowBase::SetCursorPos(SHORT x, SHORT y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
///窗口刷新
void JWindowBase::Refresh()
{
	sb_->refresh(x_, y_, width_, height_);
}
///清除矩形区域
void JWindowBase::FillRect(JRECT rect)
{
	CHAR_INFO ch;

	ch.Attributes = fColor_ | bColor_;
	ch.Char.AsciiChar = ' ';
	
	for (SHORT y=rect.Top; y<rect.Bottom; ++y)
	for (SHORT x=rect.Left; x<rect.Right; ++x)
	{
		sb_->write(x_+x, y_+y, ch);
	}
}
///绘制文本, （）x, y相对于本窗口的位置）
void JWindowBase::DrawText(SHORT x, SHORT y, const std::string& text)
{
	sb_->write(x_+x, y_+y, text, fColor_, bColor_);
}
///默认在中间绘制
void JWindowBase::DrawText(const std::string& text)
{
	SHORT x = (Width() - text.length()) / 2;
	SHORT y = (Height()-1) / 2;

	DrawText(x, y, text);
}
///绘制水平线
void JWindowBase::DrawHLine(SHORT y, SHORT x1, SHORT x2, char ch)
{
	if(x1 > x2)
		std::swap(x1, x2);

	size_t count = x2 - x1 + 1;

	std::string str(count, ch);
	DrawText(x1, y, str);
}
///绘制垂直线
void JWindowBase::DrawVLine(SHORT x, SHORT y1, SHORT y2, char ch)
{
	if(y1 > y2)
		std::swap(y1, y2);
	
	CHAR_INFO ci;

	ci.Attributes = fColor_ | bColor_;
	ci.Char.AsciiChar = ch;

	for(SHORT y = y1; y<=y2; ++y)
	{
		sb_->write(x_+x, y_+y, ci);
	}

}
///清除窗口
void JWindowBase::ClearWindow()
{
	JRECT rect = {0, 0, Width(), Height()};
	FillRect(rect);
}