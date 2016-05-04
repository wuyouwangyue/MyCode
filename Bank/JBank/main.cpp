#include "JFC/JApplication.h"
#include "JFC/JButton.h"

#include <string>

using namespace JFC;

int main()
{
	JApplication app;
	
	JButton bt(0, 0, 10, 2, "text");
	bt.Draw();
	bt.Refresh();

	JButton bt1(0, 2, 10, 1, "text");
	bt1.Show();

	return app.Exec();
}