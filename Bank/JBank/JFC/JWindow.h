#ifndef _JWINDOW_H_
#define _JWINDOW_H_

#include "JWindowBase.h"
#include "JApplication.h"

#include <vector>

namespace JFC
{
class JEvent;

class JWindow : public JWindowBase
{
public:
	JWindow();
	JWindow(SHORT x, SHORT y, SHORT width, SHORT height,
		    JWindow* parent = jApp->Root());
	virtual~JWindow();

	virtual void OnKeyEvent(JEvent *e);
	virtual void Draw();
	///设置此窗口当前选中窗口
	void SetCurrent();
	///判断此窗口是否是当前选中窗口
	bool IsCurrent() const { return this == jApp->GetCurrent(); }
	void Show();
	///添加子窗口
	void AddChild(JWindow* win);
	///删除子窗口
	void DelChild(JWindow* win);
	///查看父窗口
	JWindow* GetParent() const { return parent_; }
	///设置为可以为焦点
	void SetCanFocus() { canFocus_ = true; }

	///查找子窗口里面的第一个可以为焦点的
	JWindow* FindFirst();
	///查找子窗口里面的最后一个可以为焦点的
	JWindow* FindLast();
	///查找win窗口前一个可以为焦点的
	JWindow* FindPrev(JWindow* win);
	///查找win窗口后一个可以为焦点的
	JWindow* FindNext(JWindow* win);

protected:
	bool canFocus_;		///是否可以是焦点
	JWindow* parent_;
	std::vector<JWindow*> child_;
};

}

#endif //_JWINDOW_H_