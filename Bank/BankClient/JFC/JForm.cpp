#include "JForm.h"
#include "JEvent.h"

#include "../JFC/ScreenManager.h"

using namespace JFC;

JForm::JForm()
{

}
JForm::JForm(SHORT x, SHORT y, SHORT width, SHORT height, 
			 JWindow* parent)
	: JWindow(x, y, width, height, parent)
{

}
JForm::~JForm()
{

}

///绘制所以子窗口
void JForm::Draw()
{
	std::vector<JWindow*>::const_iterator it;

	for (it = child_.begin(); it != child_.end(); ++it)
	{
		(*it)->Draw();
	}
}
void JForm::OnKeyEvent(JEvent *e)
{
	///已经处理完毕
	if (e->IsDone())
		return ;
	///发送给自身的事件
	if (e->GetSender() == this)
		return ;

	int key = e->GetEventCode();
	JWindow* win = NULL;
	
	switch(key)
	{
	case KEY_ESC:
		e->Done();
		jScreenManager.Restore(this);
		break;

	case KEY_UP:
	case KEY_LEFT:
		win = FindPrev(e->GetSender());
		break;

	case KEY_DOWN:
	case KEY_RIGHT:
	case KEY_ENTER:
	case KEY_TAB:
		win = FindNext(e->GetSender());
		break;
	}

	if( win != NULL )
	{
		///原来的和现在的焦点都需要重新绘制
		win->Show();
		(e->GetSender())->Draw();
		(e->GetSender())->Refresh();
	}
}
void JForm::Init()
{
	std::vector<JWindow*>::const_iterator it;

	for ( it = child_.begin(); it != child_.end(); ++it )
	{
		(*it)->Init();
	}
}