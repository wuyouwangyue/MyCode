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
	///����ǽ��㣬���óɺ�װ���
	if (IsCurrent())
	{
		SetTextColor(FCOLOR_WHITE);
		SetBkColor(BCOLOR_RED);
		jApp->ShowCursor();
		SetCursorPos(x_ + currIndex_, y_);
	}
	else
	{///�ǽ������ó����װ���
		SetTextColor(FCOLOR_WHITE);
		SetBkColor(BCOLOR_BLUE);
	}

	JRECT rect = { 0, 0, Width(), Height() };
	FillRect(rect);
	
	if (mode_ == EM_NORMAL)
		DrawText(0, 0, text_);
	else
	{///����Ҫ���Ƴ� * �ţ�����ʹ������
		std::string s(text_.length(), '*');
		DrawText(0, 0, s);
	}	
}
void JEdit::OnKeyEvent(JEvent *e)
{
	int key = e->GetEventCode();

	switch(key)
	{
	///��������Ҽ����ҹ������λ��С���ַ����ĳ��ȣ��ƶ����
	case KEY_RIGHT:
		if ( currIndex_ < text_.length() )
		{
			++currIndex_;
			e->Done();
		}
		break;
	case KEY_LEFT:
		if ( currIndex_ > 0 )
		{///���������ƶ����ƶ�
			--currIndex_;
			e->Done();
		}
		break;
	case KEY_DEL:	////������û�����ֶ�����ɾ���������λ�õ��Ǹ�
		text_.erase(text_.begin() + currIndex_);
		e->Done();
		break;
	case KEY_BACK:	///�˸��ɾ�����ǰ�����һ��
		if ( currIndex_ > 0 )
		{
			text_.erase(text_.begin() + currIndex_ - 1);
			--currIndex_;	///���ҲҪ��ǰ�ƶ�һ��
		}
		e->Done();	///�¼����ڷַ�
		break;
	default:
		if ( (key > 0 && key < 256) && validator_(text_, (char)key))
		{
			text_.insert(text_.begin()+currIndex_, 1, (char)key);
			++currIndex_;	///���ҲҪ�����ƶ�
			e->Done();		///�¼��������
		}
		break;
	}

	if (e->IsDone())
		Show();
	else if ( parent_ )
		parent_->OnKeyEvent(e);
}