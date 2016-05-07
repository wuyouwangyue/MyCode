#ifndef _SCREEN_SAVER_H_
#define _SCREEN_SAVER_H_

#include "JWindowBase.h"

namespace JFC
{

///��Ļ���ݱ����࣬�ṩ������Ļ���ݵı�����ָ�
class ScreenSaver
{
public:
	ScreenSaver(JRECT rect)
		: rect_(rect_)
	{
		buffer_ = new CHAR_INFO[BUFFER_WIDTH * BUFFER_HEIGHT];
	}
	~ScreenSaver()
	{
		delete[] buffer_;
	}
	///��Ļ�洢
	void Dump()
	{
		for (SHORT y = rect_.Top; y <= rect_.Bottom; ++y)
		for (SHORT x = rect_.Left; x <= rect_.Right; ++x)
		{
			buffer_[ y * BUFFER_WIDTH + x ] = JWindowBase::sb_->buffer_[ y * BUFFER_WIDTH + x ];
		}
	}
	///��Ļ�ָ�
	void Restore()
	{
		for (SHORT y = rect_.Top; y <= rect_.Bottom; ++y)
		for (SHORT x = rect_.Left; x <= rect_.Right; ++x)
		{
			JWindowBase::sb_->buffer_[ y * BUFFER_WIDTH + x ] = buffer_[ y * BUFFER_WIDTH + x ];
		}
	}
private:
	CHAR_INFO* buffer_;
	JRECT rect_;
};

}
#endif	//_SCREEN_SAVER_H_