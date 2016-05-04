#ifndef _JWINDOW_H_
#define _JWINDOW_H_

#include "JWindowBase.h"

namespace JFC
{
class JEvent;

class JWindow : JWindowBase
{
public:
	JWindow();
	JWindow(SHORT x, SHORT y, SHORT width, SHORT height);
	virtual~JWindow();

	virtual void OnKeyEvent(JEvent *e);
	virtual void Draw();
	void Show();
};

}

#endif //_JWINDOW_H_