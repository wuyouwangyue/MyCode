#ifndef _JEDIT_H_
#define _JEDIT_H_

#include "JWindow.h"
#include <string>

namespace JFC
{

class JEvent;

typedef bool (*VALIDATOR)(const std::string&, char);
static bool DefaultValidator(const std::string& str, char ch)
{
	return true;
}

enum EchoMode
{
	EM_NORMAL,
	EM_PASSWORD
};

class JEdit : public JWindow
{
public:

	JEdit();
	JEdit(SHORT x, SHORT y, SHORT width, SHORT height,
		  const std::string& text,
		  JWindow* parent = jApp->Root(),
		  EchoMode mode = EM_NORMAL,
		  VALIDATOR validator = DefaultValidator);
	virtual ~JEdit();

	virtual void Draw();
	virtual void OnKeyEvent(JEvent *e);

	const std::string& GetText() const { return text_; }
	void SetText(const std::string& text)
	{
		text_ = text;
		currIndex_ = text_.length();
	}
	void SetValidator(VALIDATOR validator) { validator_ = validator; }

private:
	std::string text_;		//�ı�
	size_t currIndex_;			//��ǰλ��
	EchoMode mode_;			//��ʾģʽ
	VALIDATOR validator_;	//У����
};

}
#endif //_JEDIT_H_