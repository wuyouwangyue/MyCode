#ifndef _JWINDOW_H_
#define _JWINDOW_H_


namespace JFC
{
class JEvent;

class JWindow
{
public:
	JWindow();
	~JWindow();

	virtual void OnKeyEvent(JEvent *e);
};

}

#endif //_JWINDOW_H_