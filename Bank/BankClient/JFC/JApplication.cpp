#include "JApplication.h"

#include "JWindow.h"
#include "JEvent.h"
#include "ScreenManager.h"

#include "../UI/FormManager.h"

#include <conio.h>

using namespace JFC;
using namespace UI;

JApplication* JApplication::self_ = 0;

JApplication::JApplication()
	: current_(0)
{
	if(self_)
		return ;

	self_ = this;
	///֧������
	SetConsoleOutputCP(936);
	///������Ļ��������С��û���ұߵĹ�������
	COORD coord = {80, 25};
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	HideCursor();
	root_ = new JWindow(0, 0, 80, 25, 0);
	root_->Show();
}

JApplication::~JApplication()
{
	delete root_;
}
int JApplication::Exec()
{
	JForm* form = jFormManager.Get("LoginForm");
	jScreenManager.Dump(form);
	
	while(1)
	{
		///��ȡһ�������¼�
 		int key = _getch();
		
		if (key == 224)///���ܼ�����
		{
			key = (224<<8) + _getch();
		}
		else if(key == 0) ///F1~F10
		{
			key = -1 * _getch();
		}

		if(current_)
		{
			JEvent e(current_, key);
			current_->OnKeyEvent(&e);
		}
	}

	return 0;
}

void JApplication::ShowCursor() const
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci; 

	GetConsoleCursorInfo(handle, &cci);
	cci.bVisible = true;
	SetConsoleCursorInfo(handle, &cci);
}
void JApplication::HideCursor() const
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci; 

	GetConsoleCursorInfo(handle, &cci);
	cci.bVisible = false;
	SetConsoleCursorInfo(handle, &cci);
}