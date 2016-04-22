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
	int BGsize;//������С
	int BKsize;//�����С
	int num[maxn][maxn];//�����ڵ�����
	bool visit[maxn][maxn];//����ƶ�ʹ�õģ��жϺϲ�״̬��ÿ���ƶ�����ֻ�ܺϲ�һ��
	struct location loc[maxn][maxn];//���������
};

//��ʼ��
void InIt(struct BG *bg);
//��ȡĳ�����ֵ���ɫ
COLORREF GetBlockColor(int num);
//���Ʊ��������С����
void DrawBlock(struct BG *bg);
//���Ʊ��������С�����ڵ�����
void DrawNum(struct BG *bg);
//ͳ��ʣ��հ�С����
int GetLastBlock(struct BG *bg);
//����ͼ��
void Draw(struct BG *bg);

#endif //_BACKGROUND_H_