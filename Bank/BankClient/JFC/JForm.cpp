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

///���������Ӵ���
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
	///�Ѿ��������
	if (e->IsDone())
		return ;
	///���͸�������¼�
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
		///ԭ���ĺ����ڵĽ��㶼��Ҫ���»���
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