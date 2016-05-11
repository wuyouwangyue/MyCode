#include "JMessageBox.h"
#include "JWindow.h"
#include "JButton.h"
#include "JEvent.h"

#include "ScreenManager.h"
#include "../UI/FormManager.h"

#include <conio.h>

using namespace JFC;
using namespace UI;

JForm* JMessageBox::GetBox(const std::string& title, 
					  const std::string& text,
					  std::vector<std::string>& buttons)
{
	///所有按钮之间的间隔
	/*SHORT btnDistance = static_cast<SHORT>(buttons.size()) - 1;

	加上所有按钮文本的长度，文本两边预留2个长度
	for ( size_t i=0; i < buttons.size(); ++i )
		btnDistance += buttons[i].length() + 4;*/
	
	///让每个按钮定长长度为 9，求出来所有按钮的总长度
	SHORT btnLength = static_cast<SHORT>(buttons.size()) * 9;

	///求出消息框的宽度，加上边框长度,加上间隔
	SHORT width = btnLength + 4 + (buttons.size()-1) * 2;
	///消息框宽度最小为40
	if ( width < 40 )
		width = 40;
	///计算出来文本的行数, 每行文本最多(width-6)长度,向上取整
	SHORT lines = (text.length() + (width-7)) / (width-6);
	///计算消息框的高度为, 文本行数 + 9
	SHORT height = lines + 9;
	
	///计算消息框的开始位置，让消息框位于中间
	SHORT x = ( BUFFER_WIDTH - width ) / 2;
	SHORT y = ( BUFFER_HEIGHT - height ) / 2;
	
	return new JMessageBoxImpl(x, y, width, height, title, text, buttons, lines);
}


JMessageBoxImpl::JMessageBoxImpl(SHORT x, SHORT y, SHORT width, SHORT height,
								const std::string& title, const std::string& text,
								std::vector<std::string>& buttons,
								SHORT lines,JWindow* parent)
		: BankForm(x, y, width, height, parent),
		  title_(title),
		  text_(text),
		  lines_(lines)
{
	///按钮之间的间隔
	SHORT btnDistance = (width - buttons.size() * 9) / (buttons.size() + 1);
	SHORT btnX = btnDistance + x;
	SHORT btnY = height - 5 + y;

	for (size_t i=0; i < buttons.size(); ++i)
	{
		JButton* btn = new JButton(btnX, btnY, 9, 3, buttons[i], this);
		btnX += (btnDistance + 9);
	}
}
JMessageBoxImpl::~JMessageBoxImpl()
{
}

void JMessageBoxImpl::Draw()
{
	DrawBorder();

	//背景设置成深绿色
	SetBkColor(BCOLOR_CYAN);
	//重新绘制这个窗口
	JRECT rect = { 1, 1, Width()-1, Height()-1 };
	FillRect(rect);
	///绘制标题
	DrawText(2, 1, title_);
	///绘制提示文本消息,让最后一行不满的居中
	for (SHORT i=0; i < lines_; ++i)
	{
		std::string temp;
		if ( i+1 == lines_ )
		{///最后一行
			temp = text_.substr( i * (Width()-6) );
			DrawText( (Width()-temp.length()) / 2, i+3, temp );
		} 
		else
		{
			temp = text_.substr( i * (Width()-6), Width()-6 );
			DrawText(3, i+3, temp);
		}
	}

	JForm::Draw();
}
void JMessageBoxImpl::OnKeyEvent(JEvent *e)
{
	switch(e->GetEventCode())
	{
	case KEY_ESC:
	case KEY_ENTER:
		e->Done();
		jScreenManager.Restore(this);
		break;
	}

	JForm::OnKeyEvent(e);
}
int JMessageBoxImpl::Exec()
{
	while(1)
	{
		int key = _getch();

		if (key == 224)
		{
			key = (224<<8) + _getch();
		}
		
		if ( key == KEY_ESC )
			return -1;

		if ( key == KEY_ENTER )
			return FindCurrentIndex();

		JEvent e(jApp->GetCurrent(), key);
		jApp->GetCurrent()->OnKeyEvent(&e);
	}
}