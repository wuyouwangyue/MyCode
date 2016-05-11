#include "JEdit.h"
#include "JEvent.h"

using namespace JFC;

JEdit::JEdit()
	: currIndex_(0),
	  mode_(EM_NORMAL),
	  validator_(DefaultValidator)
{
	SetCanFocus();
}
JEdit::JEdit(SHORT x, SHORT y, SHORT width, SHORT height,
			  const std::string& text,
			  JWindow* parent,
			  EchoMode mode,
			  VALIDATOR validator)
	: JWindow(x, y, width, height, parent),
	text_(text),
	currIndex_(0),
	mode_(mode),
	validator_(validator)
{
	SetCanFocus();
}
JEdit::~JEdit()
{

}

void JEdit::Draw()
{
	///如果是焦点，设置成红底白字
	if (IsCurrent())
	{
		SetTextColor(FCOLOR_WHITE);
		SetBkColor(BCOLOR_RED);
		jApp->ShowCursor();
		SetCursorPos(x_ + currIndex_, y_);
	}
	else
	{///非焦点设置成蓝底白字
		SetTextColor(FCOLOR_WHITE);
		SetBkColor(BCOLOR_BLUE);
	}

	JRECT rect = { 0, 0, Width(), Height() };
	FillRect(rect);
	
	if (mode_ == EM_NORMAL)
		DrawText(0, 0, text_);
	else
	{///密码要绘制成 * 号，不能使用明文
		std::string s(text_.length(), '*');
		DrawText(0, 0, s);
	}	
}
void JEdit::OnKeyEvent(JEvent *e)
{
	int key = e->GetEventCode();

	switch(key)
	{
	///如果是向右键并且光标所在位置小于字符串的长度，移动光标
	case KEY_RIGHT:
		if ( currIndex_ < text_.length() )
		{
			++currIndex_;
			e->Done();
		}
		break;
	case KEY_LEFT:
		if ( currIndex_ > 0 )
		{///可以向左移动就移动
			--currIndex_;
			e->Done();
		}
		break;
	case KEY_DEL:	////不管有没有文字都可以删除光标所在位置的那个
		text_.erase(text_.begin() + currIndex_);
		e->Done();
		break;
	case KEY_BACK:	///退格键删除光标前面的那一个
		if ( currIndex_ > 0 )
		{
			text_.erase(text_.begin() + currIndex_ - 1);
			--currIndex_;	///光标也要向前移动一下
		}
		e->Done();	///事件不在分发
		break;
	default:
		if ( (key > 0 && key < 256) && validator_(text_, (char)key))
		{
			text_.insert(text_.begin()+currIndex_, 1, (char)key);
			++currIndex_;	///光标也要跟随移动
			e->Done();		///事件处理完毕
		}
		break;
	}

	if (e->IsDone())
		Show();
	else if ( parent_ )
		parent_->OnKeyEvent(e);
}