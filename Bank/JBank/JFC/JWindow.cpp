#include "JWindow.h"
#include "JApplication.h"

#include <algorithm>

using namespace JFC;

JWindow::JWindow()
	: parent_(0)
{
}
JWindow::JWindow(SHORT x, SHORT y, SHORT width, SHORT height, JWindow* parent)
	: JWindowBase(x, y, width, height), parent_(parent)
{
	if (parent_)
	{
		parent_->AddChild(this);
	}
}
JWindow::~JWindow()
{
	if (parent_)
	{
		parent_->DelChild(this);
	}
}

void JWindow::OnKeyEvent(JEvent *e)
{
}
void JWindow::Draw()
{
	SetTextColor(FCOLOR_BLACK);
	SetBkColor(BCOLOR_WHITE);

	ClearWindow();

}
void JWindow::Show()
{
	SetCurrent();		///���õ�ǰ����Ϊѡ�д���
	Draw();				///����
	Refresh();			///��ʾ
}
///���ô˴��ڵ�ǰѡ�д���
void JWindow::SetCurrent()
{
	if(IsCurrent() == false)
		jApp->SetCurrent(this);
}
///����Ӵ���
void JWindow::AddChild(JWindow* win)
{
	child_.push_back(win);
}
///ɾ���Ӵ���
void JWindow::DelChild(JWindow* win)
{
	child_.erase(std::remove(child_.begin(), child_.end(), win), child_.end());
}