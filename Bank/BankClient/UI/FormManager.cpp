#include "FormManager.h"

#include "LoginForm.h"
#include "MainMenuForm.h"
#include "OpenAccountForm.h"
#include "DepositForm.h"
#include "WithdrawForm.h"
#include "TransferForm.h"
#include "BalanceInquiryForm.h"
#include "ChangePasswordForm.h"
#include "CloseAccountForm.h"

#include "../JFC/JMessageBox.h"

using namespace JFC;
using namespace UI;

FormManager::FormManager()
{

	forms_["LoginForm"] = new LoginForm(0, 0, 80, 25);
	
	forms_["MainMenuForm"] = new MainMenuForm(0, 0, 80, 25);

	forms_["OpenAccountForm"] = new OpenAccountForm(0, 0, 80, 25);

	forms_["DepositForm"] = new DepositForm(0, 0, 80, 25);

	forms_["WithdrawForm"] = new WithdrawForm(0, 0, 80, 25);
	
	forms_["TransferForm"] = new TransferForm(0, 0, 80, 25);

	forms_["BalanceInquiryForm"] = new BalanceInquiryForm(0, 0, 80, 25);

	forms_["ChangePasswordForm"] = new ChangePasswordForm(0, 0, 80, 25);
	
	forms_["CloseAccountForm"] = new CloseAccountForm(0, 0, 80, 25);

	/**************************** ErrorMessage ***********************************/
	{
		std::vector<std::string> buttons;
		buttons.push_back("YES");
		std::string msg = "用户名小于3位";

		forms_["UserError"] = JMessageBox::GetBox("-ERROR-", msg, buttons);
	}
	{
		std::vector<std::string> buttons;
		buttons.push_back("YES");
		std::string msg = "密码小于6位";

		forms_["PassError"] = JMessageBox::GetBox("-ERROR-", msg, buttons);
	}
	{
		std::vector<std::string> buttons;
		buttons.push_back("YES");
		buttons.push_back("NO");

		std::string msg = "Do you want to exit ?";

		forms_["ExitMessage"] = JMessageBox::GetBox("-MESSAGE-", msg, buttons);
	}

	{
		std::vector<std::string> buttons;
		buttons.push_back("YES");
		std::string msg = "身份证号必须是 18 位";

		forms_["IdError"] = JMessageBox::GetBox("-ERROR-", msg, buttons);
	}

	{
		std::vector<std::string> buttons;
		buttons.push_back("YES");
		std::string msg = "确认密码不一致";

		forms_["PassRepeatError"] = JMessageBox::GetBox("-ERROR-", msg, buttons);
	}

	{
		std::vector<std::string> buttons;
		buttons.push_back("YES");
		std::string msg = "金额不能为空";

		forms_["MoneyError"] = JMessageBox::GetBox("-ERROR-", msg, buttons);
	}
	{
		std::vector<std::string> buttons;
		buttons.push_back("YES");
		std::string msg = "帐号小于6位";

		forms_["AccountIdError"] = JMessageBox::GetBox("-ERROR-", msg, buttons);
	}
}
FormManager::~FormManager()
{
}
