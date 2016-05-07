#include "JFC/JApplication.h"
#include "JFC/JButton.h"
#include "UI/LoginForm.h"

#include <string>

using namespace JFC;
using namespace UI;

int main()
{
	JApplication app;
	
	//JButton bt(0, 0, 10, 2, "text");
	//bt.Draw();

	//JButton bt1(0, 2, 10, 1, "text");
	//bt1.Draw();

	//app.Root()->Refresh();
	
	LoginForm login(0, 0, 80, 25);
	login.Show();

	return app.Exec();
}
 