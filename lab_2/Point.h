#ifndef _POINT_H_
#define _POINT_H_

#include "BackGround.h"

//��ȡһ������հ׵�С���������
struct location GetOnePoint(struct BG *bg);
//��ȡһ�����ֵ��2����4
int GetOneNum();
//��һ���հ׵�С��������һ�����ֵ
int SetOneNum(struct BG *bg);

#endif //_POINT_H_