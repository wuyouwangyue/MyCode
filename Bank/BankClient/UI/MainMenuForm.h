#ifndef _MAIN_MENU_FORM_H_
#define _MAIN_MENU_FORM_H_

#include "BankForm.h"
#include "../JFC/JLinkText.h"

#include <string>
#include <vector>

using namespace JFC;

namespace UI
{

class MainMenuForm : public BankForm
{
public:
	MainMenuForm();
	MainMenuForm(SHORT x, SHORT y, SHORT width, SHORT height);
	virtual ~MainMenuForm();

	virtual void Draw();
	virtual void OnKeyEvent(JEvent *e);

	void OpenAccount();		//开户
	void Deposit();			//存款
	void Withdraw();		//取款
	void Transfer();		//转账
	void BalanceInquiry();	//余额查询
	void ChangePassword();	//更改密码
	void DetailStatement();	//详细信息
	void CloseAccount();	//关闭账户
	void Quit();			//退出

	std::vector<JLinkText*>& GetItems() { return items_; }

private:
	std::vector<JLinkText*> items_;
};

}

#endif //_MAIN_MENU_FORM_H_
