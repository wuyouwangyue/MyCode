#ifndef _MOVE_H_
#define _MOVE_H_

#include "BackGround.h"

enum DIRECTION
{
	NOTTRUEDIR,
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT
};

//获取一个方向
DIRECTION NextDirection();
void Move(struct BG *bg, DIRECTION direction);
void MoveUp(struct BG *bg);
void MoveDown(struct BG *bg);
void MoveLeft(struct BG *bg);
void MoveRight(struct BG *bg);
void ClearKbhit();

#endif //_MOVE_H_