#ifndef _JFORM_H_
#define _JFORM_H_

#include "JWindow.h"

#include <vector>

namespace JFC
{

class JForm : public JWindow
{
public:
	JForm(){}
	JForm(SHORT x, SHORT y, SHORT width, SHORT height, JWindow* parent = jApp->Root())
		: JWindow(x, y, width, height, parent)
	{

	}
	virtual~JForm(){}

	///绘制所以子窗口
	virtual void Draw()
	{
		std::vector<JWindow*>::const_iterator it;

		for (it = child_.begin(); it != child_.end(); ++it)
		{
			(*it)->Draw();
		}
	}
};

}

#endif //_JFORM_H_