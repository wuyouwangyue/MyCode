#include "JWindow.h"
#include "JEvent.h"
#include "JApplication.h"

#include <algorithm>

using namespace JFC;

JWindow::JWindow()
	: parent_(0), canFocus_(false)
{
}
JWindow::JWindow(SHORT x, SHORT y, SHORT width, SHORT height, JWindow* parent)
	: JWindowBase(x, y, width, height), parent_(parent),
	  canFocus_(false)
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
	///事件已经处理完毕
	if(e->IsDone())
		return ;
	///没有处理完毕的话让父窗口继续处理
	if(parent_)
		parent_->OnKeyEvent(e);
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
	///已经是焦点窗口，不用再设置
	if (IsCurrent() == true)
		return ;
	///如果可以设置成焦点窗口
	if(canFocus_)
		jApp->SetCurrent(this);
	else
	{///否则把子窗口设置成焦点窗口
		///先遍历查看子窗口是否已经是焦点窗口，如果是不用在设置
		///如果当前焦点窗口的父窗口是本身，则说明其子窗口有焦点窗口
		if(jApp->GetCurrent() && (jApp->GetCurrent())->GetParent() == this)
			return ;
		///子窗口也没有焦点窗口，则从子节点里面查找出来一个可以设置成焦点窗口的
		JWindow *win = FindFirst();
		
		///如果子窗口里面没有可以为焦点的窗口，则把本窗口设置成焦点窗口
		if(win == NULL)
			jApp->SetCurrent(this);
		else
			jApp->SetCurrent(win);
	}
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

///查找子窗口里面的第一个可以为焦点的
JWindow* JWindow::FindFirst()
{
	std::vector<JWindow*>::const_iterator it;

	for (it = child_.begin(); it != child_.end(); ++it)
	{
		if((*it)->canFocus_ == true)
			return *it;
	}
	///没有找到
	return NULL;
}
///查找子窗口里面的最后一个可以为焦点的
JWindow* JWindow::FindLast()
{
	std::vector<JWindow*>::const_reverse_iterator ri;

	for (ri = child_.rbegin(); ri != child_.rend(); ++ri)
	{
		if((*ri)->canFocus_ == true)
			return *ri;
	}
	///没有找到
	return NULL;
}
///查找win窗口前一个可以为焦点的
JWindow* JWindow::FindPrev(JWindow* win)
{
	std::vector<JWindow*>::const_reverse_iterator ri;
	ri = std::find(child_.rbegin(), child_.rend(), win);
	
	///如果win就是第一个焦点，则找最后一个
	if (win == FindFirst())
		return FindLast();
	
	for (++ri; ri != child_.rend(); ++ri)
	{
		if ((*ri)->canFocus_ == true)
			return *ri;
	}

	return NULL;
}
///查找win窗口后一个可以为焦点的
JWindow* JWindow::FindNext(JWindow* win)
{
	std::vector<JWindow*>::const_iterator it;
	it = std::find(child_.begin(), child_.end(), win);

	///如果win是最后一个焦点，则找第一个
	if (win == FindLast())
		return FindFirst();
	
	for (++it; it != child_.end(); ++it)
	{
		if ((*it)->canFocus_ == true)
			return *it;
	}

	return NULL;
}