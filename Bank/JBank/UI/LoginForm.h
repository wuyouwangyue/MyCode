#ifndef _LOGIN_FORM_H_
#define _LOGIN_FORM_H_

#include "../JFC/JForm.h"
#include "../JFC/JButton.h"

using namespace JFC;

namespace UI
{

class JWindow;

class LoginForm : public JForm
{
public:
	LoginForm();
	LoginForm(SHORT x, SHORT y, SHORT width, SHORT height,
			  JWindow* parent = jApp->Root());
	~LoginForm();

	virtual void Draw();
	///绘制边界
	void DrawBorder();

private:
	JButton* btnLogin_;		//登陆按钮
	JButton* btnExit_;		//退出按钮
};

}

#endif //_LOGIN_FORM_H_