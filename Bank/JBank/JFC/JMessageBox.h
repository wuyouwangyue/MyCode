#ifndef _JMESSAGE_BOX_H_
#define _JMESSAGE_BOX_H_

#include "JWindow.h"
#include <string>
#include <vector>

namespace JFC
{
///因为只有一个方法，所以使用静态
///主要计算按钮个数，和消息框需要的宽度和高度
class JMessageBox
{
public:
	//左上角标题, 消息框提示内容，按钮集合
	static int Show(const std::string& title, 
					const std::string& text,
					std::vector<std::string>& buttons);
};

///消息框实现类
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
	std::string title_;		//标题
	std::string text_;		//提示内容

	SHORT btnDistance_;		//第一个按钮到最后一个按钮的间隔
	int lines_;				//文本行数
};

}


#endif //_JMESSAGE_BOX_H_