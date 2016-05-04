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
	SetCurrent();		///设置当前窗口为选中窗口
	Draw();				///绘制
	Refresh();			///显示
}
///设置此窗口当前选中窗口
void JWindow::SetCurrent()
{
	if(IsCurrent() == false)
		jApp->SetCurrent(this);
}
///添加子窗口
void JWindow::AddChild(JWindow* win)
{
	child_.push_back(win);
}
///删除子窗口
void JWindow::DelChild(JWindow* win)
{
	child_.erase(std::remove(child_.begin(), child_.end(), win), child_.end());
}