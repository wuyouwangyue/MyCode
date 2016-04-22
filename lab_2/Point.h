#ifndef _POINT_H_
#define _POINT_H_

#include "BackGround.h"

//获取一个随机空白的小方块的坐标
struct location GetOnePoint(struct BG *bg);
//获取一个随机值，2或者4
int GetOneNum();
//给一个空白的小方块设置一个随机值
int SetOneNum(struct BG *bg);

#endif //_POINT_H_