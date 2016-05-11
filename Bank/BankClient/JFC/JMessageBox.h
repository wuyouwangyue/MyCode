#ifndef _JMESSAGE_BOX_H_
#define _JMESSAGE_BOX_H_

#include "../UI/BankForm.h"

#include <string>
#include <vector>

using namespace UI;

namespace JFC
{
class JEvent;
///因为只有一个方法，所以使用静态
///主要计算按钮个数，和消息框需要的宽度和高度
class JMessageBox
{
public:
	//左上角标题, 消息框提示内容，按钮集合,返回这个消息框
	static JForm* GetBox(const std::string& title, 
					const std::string& text,
					std::vector<std::string>& buttons);
};

///消息框实现类
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
	std::string title_;		//标题
	std::string text_;		//提示内容

	int lines_;				//文本行数
};

}


#endif //_JMESSAGE_BOX_H_