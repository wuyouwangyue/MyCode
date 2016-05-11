#ifndef _BANK_FORM_H_
#define _BANK_FORM_H_

#include "../JFC/JForm.h"

using namespace JFC;

namespace UI
{

class BankForm : public JForm
{
public:
	BankForm(){}
	BankForm(SHORT x, SHORT y, SHORT width, SHORT height, JWindow* parent = jApp->Root())
		: JForm(x, y, width, height, parent)
	{
	}
	void DrawBorder()
	{
		ClearWindow();

		SetTextColor(FCOLOR_YELLO);
		SetBkColor(BCOLOR_RED);

		///上下边界
		DrawHLine(0, 0, Width()-1, '-');
		DrawHLine(Height()-1, 0, Width()-1, '-');

		///左右边界
		DrawVLine(0, 1, Height()-2, ' ');
		DrawVLine(Width()-1, 1, Height()-2, ' ');
	}
};

}

#endif //_BANK_FORM_H_