#ifndef _LOGIN_FORM_H_
#define _LOGIN_FORM_H_

#include "../JFC/JForm.h"
#include "../JFC/JButton.h"
#include "../JFC/JLabel.h"
#include "../JFC/JEdit.h"

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
	virtual void OnKeyEvent(JEvent *e);
	virtual void Draw();
	///���Ʊ߽�
	void DrawBorder();

private:
	JButton* btnLogin_;		//��½��ť
	JButton* btnExit_;		//�˳���ť

	JLabel* lblUser_;
	JEdit*  editUser_;
	JLabel* lblUserTip_;

	JLabel* lblPass_;
	JEdit*  editPass_;
	JLabel* lblPassTip_;
};

}

#endif //_LOGIN_FORM_H_