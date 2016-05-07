#ifndef _JMESSAGE_BOX_H_
#define _JMESSAGE_BOX_H_

#include "JWindow.h"
#include <string>
#include <vector>

namespace JFC
{
///��Ϊֻ��һ������������ʹ�þ�̬
///��Ҫ���㰴ť����������Ϣ����Ҫ�Ŀ�Ⱥ͸߶�
class JMessageBox
{
public:
	//���ϽǱ���, ��Ϣ����ʾ���ݣ���ť����
	static int Show(const std::string& title, 
					const std::string& text,
					std::vector<std::string>& buttons);
};

///��Ϣ��ʵ����
class JMessageBoxImpl : public JWindow
{
public:
	JMessageBoxImpl(SHORT x, SHORT y, SHORT width, SHORT height,
					const std::string& title, const std::string& text,
					std::vector<std::string>& buttons,
					SHORT btnDistance, SHORT lines,
					JWindow* parent = jApp->Root());
	~JMessageBoxImpl();

	virtual void Draw();
	int Exec();

private:
	std::string title_;		//����
	std::string text_;		//��ʾ����

	SHORT btnDistance_;		//��һ����ť�����һ����ť�ļ��
	int lines_;				//�ı�����
};

}


#endif //_JMESSAGE_BOX_H_