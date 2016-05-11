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

	void OpenAccount();		//����
	void Deposit();			//���
	void Withdraw();		//ȡ��
	void Transfer();		//ת��
	void BalanceInquiry();	//����ѯ
	void ChangePassword();	//��������
	void DetailStatement();	//��ϸ��Ϣ
	void CloseAccount();	//�ر��˻�
	void Quit();			//�˳�

	std::vector<JLinkText*>& GetItems() { return items_; }

private:
	std::vector<JLinkText*> items_;
};

}

#endif //_MAIN_MENU_FORM_H_
