#ifndef _FORM_MANAGER_H_
#define _FORM_MANAGER_H_

#include "../JFC/JForm.h"
#include "../../Public/Singleton.h"

#include <string>
#include <map>

using namespace PUBLIC;
using namespace JFC;

namespace UI
{

class FormManager
{
	friend class Singleton<FormManager>;
public:
	void Add(const std::string& name, JForm* form)
	{///添加一个界面
		forms_[name] = form;
	}
	JForm* Get(const std::string& name)
	{///获取一个界面
		return forms_[name];
	}
	///查找这个窗口是否已经存在
	JForm* Find(const std::string& name)
	{
		std::map<std::string, JForm*>::iterator it;

		for(it = forms_.begin(); it != forms_.end(); ++it)
		{
			if ( it->first == name )
				return it->second;
		}

		return NULL;
	}

private:
	std::map<std::string, JForm*> forms_;
	FormManager();
	~FormManager();
};

#define jFormManager Singleton<FormManager>::Instance()

}

#endif //_FORM_MANAGER_H_