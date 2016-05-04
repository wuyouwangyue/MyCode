#include "JApplication.h"

#include "JWindow.h"
#include "JEvent.h"

#include <conio.h>

using namespace JFC;

JApplication* JApplication::self_ = 0;

JApplication::JApplication()
{
	if(self_)
		return ;

	self_ = this;
	root_ = new JWindow;
	current_ = root_;
}

JApplication::~JApplication()
{
	delete root_;
}
int JApplication::Exec()
{
	while(1)
	{
		///获取一个键盘事件
		int key = _getch();

		if(current_)
		{
			JEvent e(current_, key);
			current_->OnKeyEvent(&e);
		}
	}

	return 0;
}