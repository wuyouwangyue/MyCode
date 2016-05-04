#ifndef _SCREENBUFFER_H_
#define _SCREENBUFFER_H_

#include <Windows.h>
#include <string>

namespace JFC
{

//屏幕缓冲区的宽度和高度
#define BUFFER_WIDTH 80
#define BUFFER_HEIGHT 25

typedef SMALL_RECT JRECT;

///屏幕缓冲区类，用来保存屏幕的内容，打印输出
class ScreenBuffer
{
public:
	ScreenBuffer()
	{
		buffer_ = new CHAR_INFO[BUFFER_HEIGHT * BUFFER_WIDTH];
	}
	~ScreenBuffer()
	{
		delete[] buffer_;
	}
	
	///向xy位置写入一个字符
	void write(SHORT x, SHORT y, CHAR_INFO ch)
	{
		buffer_[x * BUFFER_WIDTH + y] = ch;
	}
	///向xy位置写入一个字符串
	void write(SHORT x, SHORT y, std::string str, WORD fColor, WORD bColor)
	{
		CHAR_INFO ch;
		ch.Attributes = fColor | bColor;
		
		for (size_t i=0; i < str.length(); ++i)
		{
			ch.Char.AsciiChar = str[i];
			write(x, y+i, ch);
		}
	}
	///刷新到屏幕
	void refresh(SHORT x, SHORT y, SHORT width, SHORT height)
	{
		COORD size = {BUFFER_WIDTH, BUFFER_HEIGHT};
		COORD coord = {x, y};
		JRECT rect = {x, y, x+width-1, y+height-1};

		WriteConsoleOutput(
			GetStdHandle(STD_OUTPUT_HANDLE),
			buffer_,
			size,
			coord,
			&rect
			);
	}

public:
	CHAR_INFO* buffer_;
};

}

#endif //_SCREENBUFFER_H_