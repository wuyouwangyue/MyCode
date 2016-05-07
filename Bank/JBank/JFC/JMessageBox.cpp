#include "JMessageBox.h"

using namespace JFC;

int JMessageBox::Show(const std::string& title, 
					  const std::string& text,
					  std::vector<std::string>& buttons)
{
	///所有按钮之间的间隔
	SHORT btnDistance = static_cast<SHORT>(buttons.size()) - 1;
}


JMessageBoxImpl::JMessageBoxImpl(SHORT x, SHORT y, SHORT width, SHORT height,
								const std::string& title, const std::string& text,
								std::vector<std::string>& buttons,
								SHORT btnDistance, SHORT lines,JWindow* parent)
		: JWindow(x, y, width, height, parent),
		  title_(title),
		  text_(text),
		  btnDistance_(btnDistance_),
		  lines_(lines)
{
}
JMessageBoxImpl::~JMessageBoxImpl()
{

}

void JMessageBoxImpl::Draw()
{

}
int JMessageBoxImpl::Exec()
{
return 0;
}