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
	///�¼��Ѿ��������
	if(e->IsDone())
		return ;
	///û�д�����ϵĻ��ø����ڼ�������
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
	SetCurrent();		///���õ�ǰ����Ϊѡ�д���
	Draw();				///����
	Refresh();			///��ʾ
}
///���ô˴��ڵ�ǰѡ�д���
void JWindow::SetCurrent()
{
	///�Ѿ��ǽ��㴰�ڣ�����������
	if (IsCurrent() == true)
		return ;
	///����������óɽ��㴰��
	if(canFocus_)
		jApp->SetCurrent(this);
	else
	{///������Ӵ������óɽ��㴰��
		///�ȱ����鿴�Ӵ����Ƿ��Ѿ��ǽ��㴰�ڣ�����ǲ���������
		///�����ǰ���㴰�ڵĸ������Ǳ�����˵�����Ӵ����н��㴰��
		if(jApp->GetCurrent() && (jApp->GetCurrent())->GetParent() == this)
			return ;
		///�Ӵ���Ҳû�н��㴰�ڣ�����ӽڵ�������ҳ���һ���������óɽ��㴰�ڵ�
		JWindow *win = FindFirst();
		
		///����Ӵ�������û�п���Ϊ����Ĵ��ڣ���ѱ��������óɽ��㴰��
		if(win == NULL)
			jApp->SetCurrent(this);
		else
			jApp->SetCurrent(win);
	}
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

///�����Ӵ�������ĵ�һ������Ϊ�����
JWindow* JWindow::FindFirst()
{
	std::vector<JWindow*>::const_iterator it;

	for (it = child_.begin(); it != child_.end(); ++it)
	{
		if((*it)->canFocus_ == true)
			return *it;
	}
	///û���ҵ�
	return NULL;
}
///�����Ӵ�����������һ������Ϊ�����
JWindow* JWindow::FindLast()
{
	std::vector<JWindow*>::const_reverse_iterator ri;

	for (ri = child_.rbegin(); ri != child_.rend(); ++ri)
	{
		if((*ri)->canFocus_ == true)
			return *ri;
	}
	///û���ҵ�
	return NULL;
}
///����win����ǰһ������Ϊ�����
JWindow* JWindow::FindPrev(JWindow* win)
{
	std::vector<JWindow*>::const_reverse_iterator ri;
	ri = std::find(child_.rbegin(), child_.rend(), win);
	
	///���win���ǵ�һ�����㣬�������һ��
	if (win == FindFirst())
		return FindLast();
	
	for (++ri; ri != child_.rend(); ++ri)
	{
		if ((*ri)->canFocus_ == true)
			return *ri;
	}

	return NULL;
}
///����win���ں�һ������Ϊ�����
JWindow* JWindow::FindNext(JWindow* win)
{
	std::vector<JWindow*>::const_iterator it;
	it = std::find(child_.begin(), child_.end(), win);

	///���win�����һ�����㣬���ҵ�һ��
	if (win == FindLast())
		return FindFirst();
	
	for (++it; it != child_.end(); ++it)
	{
		if ((*it)->canFocus_ == true)
			return *it;
	}

	return NULL;
}