#ifndef _JWINDOW_BASE_H_
#define _JWINDOW_BASE_H_

#include <string>
#include "ScreenBuffer.h"

namespace JFC
{


	// ��ɫ
	// ��ɫ
	// ��ɫ
	// ��ɫ
	// ��ɫ
	// ���
	// ��ɫ
	// ����
	// ���
	// ����
	// ����
	// ����
	// ����
	// �����
	// ��ɫ
	// ��ɫ
#define FCOLOR_BLACK			0
#define FCOLOR_BLUE				FOREGROUND_BLUE
#define FCOLOR_GREEN			FOREGROUND_GREEN
#define FCOLOR_CYAN				FOREGROUND_BLUE | FOREGROUND_GREEN
#define FCOLOR_RED				FOREGROUND_RED
#define FCOLOR_MAGENTA			FOREGROUND_RED | FOREGROUND_BLUE
#define FCOLOR_BLOWN			FOREGROUND_RED | FOREGROUND_GREEN
#define FCOLOR_GRAY				FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
#define FCOLOR_DARKGRAY			FCOLOR_BLACK + FOREGROUND_INTENSITY
#define FCOLOR_LIGHTBLUE		FCOLOR_BLUE + FOREGROUND_INTENSITY
#define FCOLOR_LIGHTGREEN		FCOLOR_GREEN + FOREGROUND_INTENSITY
#define FCOLOR_LIGHTCYAN		FCOLOR_CYAN + FOREGROUND_INTENSITY
#define FCOLOR_LIGHTRED			FCOLOR_RED + FOREGROUND_INTENSITY
#define FCOLOR_LIGHTMAGENTA		FCOLOR_MAGENTA + FOREGROUND_INTENSITY
#define FCOLOR_YELLO			FCOLOR_BLOWN + FOREGROUND_INTENSITY
#define FCOLOR_WHITE			FCOLOR_GRAY + FOREGROUND_INTENSITY

#define BCOLOR_BLACK			0
#define BCOLOR_BLUE				BACKGROUND_BLUE
#define BCOLOR_GREEN			BACKGROUND_GREEN
#define BCOLOR_CYAN				BACKGROUND_BLUE | BACKGROUND_GREEN
#define BCOLOR_RED				BACKGROUND_RED
#define BCOLOR_MAGENTA			BACKGROUND_RED | BACKGROUND_BLUE
#define BCOLOR_BLOWN			BACKGROUND_RED | BACKGROUND_GREEN
#define BCOLOR_GRAY				BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE
#define BCOLOR_DARKGRAY			BCOLOR_BLACK + BACKGROUND_INTENSITY
#define BCOLOR_LIGHTBLUE		BCOLOR_BLUE + BACKGROUND_INTENSITY
#define BCOLOR_LIGHTGREEN		BCOLOR_GREEN + BACKGROUND_INTENSITY
#define BCOLOR_LIGHTCYAN		BCOLOR_CYAN + BACKGROUND_INTENSITY
#define BCOLOR_LIGHTRED			BCOLOR_RED + BACKGROUND_INTENSITY
#define BCOLOR_LIGHTMAGENTA		BCOLOR_MAGENTA + BACKGROUND_INTENSITY
#define BCOLOR_YELLO			BCOLOR_BLOWN + BACKGROUND_INTENSITY
#define BCOLOR_WHITE			BCOLOR_GRAY + BACKGROUND_INTENSITY

class JWindowBase
{
public:
	JWindowBase();
	JWindowBase(SHORT x, SHORT y, SHORT width, SHORT height);
	~JWindowBase();
	
	///��ȡ���
	SHORT Width() const { return width_; }
	///��ȡ�߶�
	SHORT Height() const { return height_; }

	///��ȡǰ��ɫ
	WORD GetTextColor() const { return fColor_; }
	///����ǰ��ɫ
	void SetTextColor(WORD color){ fColor_ = color; }

	///��ȡ����ɫ
	WORD GetBkColor() const { return bColor_; }
	///���ñ���ɫ
	void SetBkColor(WORD color) { bColor_ = color; }

	///���ù��λ��
	void SetCursorPos(SHORT x, SHORT y);
	///����ˢ��
	void Refresh();
	///�����������
	void FillRect(JRECT rect);
	///�����ı�
	void DrawText(SHORT x, SHORT y, const std::string& text);
	void DrawText(const std::string& text);
	///����ˮƽ��
	void DrawHLine(SHORT y, SHORT x1, SHORT x2, char ch);
	///���ƴ�ֱ��
	void DrawVLine(SHORT x, SHORT y1, SHORT y2, char ch);
	///�������
	void ClearWindow();
public:
	static ScreenBuffer* sb_;

protected:
	WORD fColor_;	///ǰ��ɫ���ı���ɫ��
	WORD bColor_;	///����ɫ
	SHORT x_;		///��������x
	SHORT y_;		///��������y
	SHORT width_;	///���ڿ��
	SHORT height_;	///���ڸ߶�
};

}
#endif //_JWINDOW_BASE_H_