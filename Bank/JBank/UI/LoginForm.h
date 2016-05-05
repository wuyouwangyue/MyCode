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
	///���Ʊ߽�
	void DrawBorder();

private:
	JButton* btnLogin_;		//��½��ť
	JButton* btnExit_;		//�˳���ť
};

}

#endif //_LOGIN_FORM_H_