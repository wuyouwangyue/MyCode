#include "MainMenuForm.h"
#include "FormManager.h"

#include "../JFC/JEvent.h"
#include "../JFC/ScreenManager.h"

#include <conio.h>

using namespace UI;
using namespace JFC;

MainMenuForm::MainMenuForm()
{
}
MainMenuForm::MainMenuForm(SHORT x, SHORT y, SHORT width, SHORT height)
	: BankForm(x, y, width, height)
{
	char* texts[] = {
		"1. Open Account",
		"2. To Deposit Money",
		"3. To Withdraw Deposited Money",
		"4. To Transfer Of Account",
		"5. Balance Inquiry",
		"6. Change Password Of Account",
		"7. Detailed Statement",
		"8. Close Account ",
		"0. Exit"
	};

	for ( size_t i=0; i<9; ++i )
	{	
		items_.push_back( new JLinkText(22, i*2+5, 40, 1, texts[i], this) );
	}
}

MainMenuForm::~MainMenuForm()
{
}


void MainMenuForm::Draw()
{
	DrawBorder();
	SetTextColor(FCOLOR_BLUE);
	SetBkColor(BCOLOR_WHITE);
	DrawText(33, 2, "Main Menu List");
	SetTextColor(FCOLOR_BLUE);
	DrawHLine(3, 25, 54, '-');

	JForm::Draw();
}

void MainMenuForm::OnKeyEvent(JEvent *e)
{
	int key = e->GetEventCode();
	///如果按下了回车键
	if ( key == KEY_ENTER )
	{
		///直接转换成对应的数字字符，和数字快捷键统一处理
		key = (FindCurrentIndex() + 1) % 9 + 48;
	}

	switch( key )
	{
	case KEY_(1):
		e->Done();
		OpenAccount();
		break;
	case KEY_(2):
		e->Done();
		Deposit();
		break;
	case KEY_(3):
		e->Done();
		Withdraw();
		break;
	case KEY_(4):
		e->Done();
		Transfer();
		break;
	case KEY_(5):
		e->Done();
		BalanceInquiry();
		break;
	case KEY_(6):
		e->Done();
		ChangePassword();
		break;
	case KEY_(7):
		e->Done();
		DetailStatement();
		break;
	case KEY_(8):
		e->Done();
		CloseAccount();
		break;
	case KEY_(0):
	case KEY_ESC:
		e->Done();
		Quit();
		break;
	default:
		break;
	}

	JForm::OnKeyEvent(e);
}

void MainMenuForm::OpenAccount()
{
	JForm* form = jFormManager.Find("OpenAccountForm");
	jScreenManager.Dump(form);
}
void MainMenuForm::Deposit()
{
	JForm* form = jFormManager.Find("DepositForm");
	jScreenManager.Dump(form);
}
void MainMenuForm::Withdraw()
{
	JForm* form = jFormManager.Find("WithdrawForm");
	jScreenManager.Dump(form);
}
void MainMenuForm::Transfer()
{
	JForm* form = jFormManager.Find("TransferForm");
	jScreenManager.Dump(form);
}
void MainMenuForm::BalanceInquiry()
{
	JForm* form = jFormManager.Find("BalanceInquiryForm");
	jScreenManager.Dump(form);
}
void MainMenuForm::ChangePassword()
{
	JForm* form = jFormManager.Find("ChangePasswordForm");
	jScreenManager.Dump(form);
}
void MainMenuForm::DetailStatement()
{

}
void MainMenuForm::CloseAccount()
{
	JForm* form = jFormManager.Find("CloseAccountForm");
	jScreenManager.Dump(form);
}
void MainMenuForm::Quit()
{
	JForm* from = jFormManager.Get( "ExitMessage" );

	jScreenManager.Dump( from );
	int res = from->Exec();
	jScreenManager.Restore( from );
	///确定退出
	if ( res == 0 )
		jScreenManager.Restore( this );
}