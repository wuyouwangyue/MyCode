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
	///���ô˴��ڵ�ǰѡ�д���
	void SetCurrent();
	///�жϴ˴����Ƿ��ǵ�ǰѡ�д���
	bool IsCurrent() const { return this == jApp->GetCurrent(); }
	void Show();
	///����Ӵ���
	void AddChild(JWindow* win);
	///ɾ���Ӵ���
	void DelChild(JWindow* win);

protected:
	JWindow* parent_;
	std::vector<JWindow*> child_;
};

}

#endif //_JWINDOW_H_