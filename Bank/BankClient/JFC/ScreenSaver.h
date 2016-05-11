#ifndef _SCREEN_SAVER_H_
#define _SCREEN_SAVER_H_

#include "JWindowBase.h"

namespace JFC
{

///屏幕数据保存类，提供部分屏幕数据的保存与恢复
class ScreenSaver
{
public:
	ScreenSaver(JRECT rect)
		: rect_(rect)
	{
		buffer_ = new CHAR_INFO[BUFFER_WIDTH * BUFFER_HEIGHT];
	}
	~ScreenSaver()
	{
		delete[] buffer_;
	}
	///屏幕存储
	void Dump()
	{
		for (SHORT y = rect_.Top; y <= rect_.Bottom; ++y)
		for (SHORT x = rect_.Left; x <= rect_.Right; ++x)
		{
			buffer_[ y * BUFFER_WIDTH + x ] = JWindowBase::sb_->buffer_[ y * BUFFER_WIDTH + x ];
		}
	}
	///屏幕恢复
	void Restore()
	{
		for (SHORT y = rect_.Top; y <= rect_.Bottom; ++y)
		for (SHORT x = rect_.Left; x <= rect_.Right; ++x)
		{
			JWindowBase::sb_->buffer_[ y * BUFFER_WIDTH + x ] = buffer_[ y * BUFFER_WIDTH + x ];
		}

		JWindowBase::sb_->refresh(rect_.Left, rect_.Top,  rect_.Right-rect_.Left+1, rect_.Bottom-rect_.Top+1);
	}
private:
	CHAR_INFO* buffer_;
	JRECT rect_;
};

}
#endif	//_SCREEN_SAVER_H_