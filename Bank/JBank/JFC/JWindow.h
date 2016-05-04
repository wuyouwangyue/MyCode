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

protected:
	JWindow* parent_;
	std::vector<JWindow*> child_;
};

}

#endif //_JWINDOW_H_