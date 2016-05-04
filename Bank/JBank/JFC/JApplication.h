#ifndef _JAPPLICATION_H_
#define _JAPPLICATION_H_

namespace JFC
{

class JWindow;

class JApplication
{
public:
	JApplication();
	~JApplication();
	
	static JApplication* Instance() { return self_; }
	void SetCurrent(JWindow* win){ current_ = win; } 
	JWindow* GetCurrent() const{ return current_; }
	JWindow* Root() const { return root_; }

	int Exec();

private:
	static JApplication* self_;
	JWindow* current_;
	JWindow* root_;
};

#define jApp JApplication::Instance()

}
#endif //_JAPPLICATION_H_