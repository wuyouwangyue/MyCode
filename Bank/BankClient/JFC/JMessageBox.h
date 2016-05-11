#ifndef _JMESSAGE_BOX_H_
#define _JMESSAGE_BOX_H_

#include "../UI/BankForm.h"

#include <string>
#include <vector>

using namespace UI;

namespace JFC
{
class JEvent;
///��Ϊֻ��һ������������ʹ�þ�̬
///��Ҫ���㰴ť����������Ϣ����Ҫ�Ŀ�Ⱥ͸߶�
class JMessageBox
{
public:
	//���ϽǱ���, ��Ϣ����ʾ���ݣ���ť����,���������Ϣ��
	static JForm* GetBox(const std::string& title, 
					const std::string& text,
					std::vector<std::string>& buttons);
};

///��Ϣ��ʵ����
class JMessageBoxImpl : public BankForm
{
public:
	JMessageBoxImpl(SHORT x, SHORT y, SHORT width, SHORT height,
					const std::string& title, const std::string& text,
					std::vector<std::string>& buttons,
					SHORT lines, JWindow* parent = jApp->Root());
	~JMessageBoxImpl();

	virtual void Draw();
	virtual void OnKeyEvent(JEvent *e);
	virtual int Exec();

private:
	std::string title_;		//����
	std::string text_;		//��ʾ����

	int lines_;				//�ı�����
};

}


#endif //_JMESSAGE_BOX_H_