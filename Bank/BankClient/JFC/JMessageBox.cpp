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
	///���а�ť֮��ļ��
	/*SHORT btnDistance = static_cast<SHORT>(buttons.size()) - 1;

	�������а�ť�ı��ĳ��ȣ��ı�����Ԥ��2������
	for ( size_t i=0; i < buttons.size(); ++i )
		btnDistance += buttons[i].length() + 4;*/
	
	///��ÿ����ť��������Ϊ 9����������а�ť���ܳ���
	SHORT btnLength = static_cast<SHORT>(buttons.size()) * 9;

	///�����Ϣ��Ŀ�ȣ����ϱ߿򳤶�,���ϼ��
	SHORT width = btnLength + 4 + (buttons.size()-1) * 2;
	///��Ϣ������СΪ40
	if ( width < 40 )
		width = 40;
	///��������ı�������, ÿ���ı����(width-6)����,����ȡ��
	SHORT lines = (text.length() + (width-7)) / (width-6);
	///������Ϣ��ĸ߶�Ϊ, �ı����� + 9
	SHORT height = lines + 9;
	
	///������Ϣ��Ŀ�ʼλ�ã�����Ϣ��λ���м�
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
	///��ť֮��ļ��
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

	//�������ó�����ɫ
	SetBkColor(BCOLOR_CYAN);
	//���»����������
	JRECT rect = { 1, 1, Width()-1, Height()-1 };
	FillRect(rect);
	///���Ʊ���
	DrawText(2, 1, title_);
	///������ʾ�ı���Ϣ,�����һ�в����ľ���
	for (SHORT i=0; i < lines_; ++i)
	{
		std::string temp;
		if ( i+1 == lines_ )
		{///���һ��
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