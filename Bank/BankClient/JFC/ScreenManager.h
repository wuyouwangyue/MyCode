#ifndef _SCREEN_MANAGER_H_
#define _SCREEN_MANAGER_H_

#include "ScreenSaver.h"
#include "JWindow.h"
#include "JForm.h"

#include "../../Public/Singleton.h"

#include <map>

using namespace PUBLIC;

namespace JFC
{
///管理屏幕
class ScreenManager
{
	friend class Singleton<ScreenManager>;
public:
	void Dump(JForm* form, JWindow* win = jApp->GetCurrent())
	{
		///焦点被更改
		if ( win->IsCurrent() == false )
		{
			JWindow* temp = jApp->GetCurrent();
			win->SetCurrent();
			temp->Draw();
			temp->Refresh();
		}

		ScreenSaver *screensaver = new ScreenSaver(form->GetRect());

		screensaver->Dump();

		screens_[form] = screensaver;
		currents_[form] = win;

		form->Show();
	}
	void Restore(JForm* form)
	{///恢复屏幕

		if (Find(form))
		{
			screens_[form]->Restore();
			currents_[form]->Show();

			screens_.erase(form);
			currents_.erase(form);
		}
	}

private:
	std::map<JForm*, ScreenSaver*> screens_; ///储存屏幕
	std::map<JForm*, JWindow*> currents_;	 ///储存焦点
	
	ScreenSaver* Find(JForm* form)
	{
		std::map<JForm*, ScreenSaver*>::iterator it;

		for ( it = screens_.begin(); it != screens_.end(); ++it)
		{
			if ( form == it->first )
				return it->second;
		}

		return NULL;
	}
	
	///单例模式，把构造函数和析构函数声明为私有
	ScreenManager(){}
	~ScreenManager(){};
};

#ifndef jScreenManager
#define jScreenManager Singleton<ScreenManager>::Instance()
#endif //jScreenManager

}

#endif //_SCREEN_MANAGER_H_