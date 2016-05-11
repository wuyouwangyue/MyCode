#ifndef _JEVENT_H_
#define _JEVENT_H_

namespace JFC
{

class JWindow;

class JEvent
{
public:
	JEvent(JWindow* sender, int code)
		: sender_(sender), code_(code), done_(false)
	{

	}
	JWindow* GetSender() const { return sender_; }
	int GetEventCode() const { return code_; }
	///�¼����
	void Done() {done_ = true;}
	bool IsDone() const { return done_ == true; }
	
private:
	JWindow* sender_;	///�¼�Ҫ���͵��Ĵ���
	int code_;			///�¼����
	bool done_;			//�¼��Ƿ������
};
}
#endif //_JEVENT_H_