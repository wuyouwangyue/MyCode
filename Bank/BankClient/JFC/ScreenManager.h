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
///������Ļ
class ScreenManager
{
	friend class Singleton<ScreenManager>;
public:
	void Dump(JForm* form, JWindow* win = jApp->GetCurrent())
	{
		///���㱻����
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
	{///�ָ���Ļ

		if (Find(form))
		{
			screens_[form]->Restore();
			currents_[form]->Show();

			screens_.erase(form);
			currents_.erase(form);
		}
	}

private:
	std::map<JForm*, ScreenSaver*> screens_; ///������Ļ
	std::map<JForm*, JWindow*> currents_;	 ///���潹��
	
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
	
	///����ģʽ���ѹ��캯����������������Ϊ˽��
	ScreenManager(){}
	~ScreenManager(){};
};

#ifndef jScreenManager
#define jScreenManager Singleton<ScreenManager>::Instance()
#endif //jScreenManager

}

#endif //_SCREEN_MANAGER_H_