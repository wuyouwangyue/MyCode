#include "JWindow.h"
#include "JApplication.h"

using namespace JFC;

JWindow::JWindow()
{
}
JWindow::JWindow(SHORT x, SHORT y, SHORT width, SHORT height) 
	: JWindowBase(x, y, width, height)
{

}
JWindow::~JWindow()
{
}

void JWindow::OnKeyEvent(JEvent *e)
{
}
void JWindow::Draw()
{
	SetTextColor(FCOLOR_BLACK);
	SetBkColor(BCOLOR_WHITE);

	ClearWindow();

}
void JWindow::Show()
{
	jApp->SetCurrent(this);
	Draw();
	Refresh();
}