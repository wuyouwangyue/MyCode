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
	///事件完成
	void Done() {done_ = true;}
	bool IsDone() const { return done_ == true; }
	
private:
	JWindow* sender_;	///事件要发送到的窗口
	int code_;			///事件编号
	bool done_;			//事件是否处理完毕
};
}
#endif //_JEVENT_H_