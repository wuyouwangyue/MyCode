#ifndef _SCREENBUFFER_H_
#define _SCREENBUFFER_H_

#include <Windows.h>
#include <string>

namespace JFC
{

//��Ļ�������Ŀ�Ⱥ͸߶�
#define BUFFER_WIDTH 80
#define BUFFER_HEIGHT 25

typedef SMALL_RECT JRECT;

///��Ļ�������࣬����������Ļ�����ݣ���ӡ���
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
	
	///��xyλ��д��һ���ַ�
	void write(SHORT x, SHORT y, CHAR_INFO ch)
	{
		buffer_[x * BUFFER_WIDTH + y] = ch;
	}
	///��xyλ��д��һ���ַ���
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
	///ˢ�µ���Ļ
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