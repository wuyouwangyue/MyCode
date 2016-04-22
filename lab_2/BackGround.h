#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include <graphics.h>

const int maxn = 5;


#define BACKCOLOR	RGB(213,213,213)
#define COLOR_0		RGB(232,232,232)
#define COLOR_2		RGB(228,209,78)
#define COLOR_4		RGB(188,147,122)
#define COLOR_8		RGB(214,125,29)
#define COLOR_16	RGB(109,202,40)
#define COLOR_32	RGB(143,153,219)
#define COLOR_64	RGB(237,139,166)
#define COLOR_128	RGB(118,220,194)
#define COLOR_256	RGB(149,227,111)
#define COLOR_512	RGB(255,151,47)
#define COLOR_1024	RGB(128,128,255)
#define COLOR_2048	RGB(255,98,98)


struct location
{
	int x, y;
};

struct BG
{
	int BGsize;//背景大小
	int BKsize;//方格大小
	int num[maxn][maxn];//方格内的数字
	bool visit[maxn][maxn];//配合移动使用的，判断合并状态，每次移动数字只能合并一次
	struct location loc[maxn][maxn];//方格的坐标
};

//初始化
void InIt(struct BG *bg);
//获取某个数字的颜色
COLORREF GetBlockColor(int num);
//绘制背景上面的小方块
void DrawBlock(struct BG *bg);
//绘制背景上面的小方块内的数字
void DrawNum(struct BG *bg);
//统计剩余空白小方块
int GetLastBlock(struct BG *bg);
//绘制图像
void Draw(struct BG *bg);

#endif //_BACKGROUND_H_