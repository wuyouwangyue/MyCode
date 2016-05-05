#ifndef _JWINDOW_BASE_H_
#define _JWINDOW_BASE_H_

#include <string>
#include "ScreenBuffer.h"

namespace JFC
{


	// 黑色
	// 蓝色
	// 绿色
	// 青色
	// 红色
	// 洋红
	// 棕色
	// 淡灰
	// 深灰
	// 淡蓝
	// 淡绿
	// 淡青
	// 淡红
	// 淡洋红
	// 黄色
	// 白色
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
	
	///获取宽度
	SHORT Width() const { return width_; }
	///获取高度
	SHORT Height() const { return height_; }

	///获取前景色
	WORD GetTextColor() const { return fColor_; }
	///设置前景色
	void SetTextColor(WORD color){ fColor_ = color; }

	///获取背景色
	WORD GetBkColor() const { return bColor_; }
	///设置背景色
	void SetBkColor(WORD color) { bColor_ = color; }

	///设置光标位置
	void SetCursorPos(SHORT x, SHORT y);
	///窗口刷新
	void Refresh();
	///清除矩形区域
	void FillRect(JRECT rect);
	///绘制文本
	void DrawText(SHORT x, SHORT y, const std::string& text);
	void DrawText(const std::string& text);
	///绘制水平线
	void DrawHLine(SHORT y, SHORT x1, SHORT x2, char ch);
	///绘制垂直线
	void DrawVLine(SHORT x, SHORT y1, SHORT y2, char ch);
	///清除窗口
	void ClearWindow();
public:
	static ScreenBuffer* sb_;

protected:
	WORD fColor_;	///前景色（文本颜色）
	WORD bColor_;	///背景色
	SHORT x_;		///窗口坐标x
	SHORT y_;		///窗口坐标y
	SHORT width_;	///窗口宽度
	SHORT height_;	///窗口高度
};

}
#endif //_JWINDOW_BASE_H_