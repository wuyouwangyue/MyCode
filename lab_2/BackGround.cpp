#include "BackGround.h"
#include "Point.h"

#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


void InIt(struct BG *bg)
{
	int i, j;

	initgraph(bg->BGsize, bg->BGsize);
	setbkcolor(BACKCOLOR);
	cleardevice();

	BeginBatchDraw();

	srand(time(NULL));
	//��ȡ�������С���鸳ֵ
	SetOneNum(bg);
	SetOneNum(bg);

	//��������
	for(i=1; i<=4; i++)
	for(j=1; j<=4; j++)
	{
		bg->loc[i][j].x = (j-1) * (bg->BKsize + 10) + 5;
		bg->loc[i][j].y = (i-1) * (bg->BKsize + 10) + 5;
	}
	
	Draw(bg);
}
//��ȡĳ�����ֵ���ɫ
COLORREF GetBlockColor(int num)
{
	COLORREF res = 0;

	switch(num)
	{
	case 0:	   res = COLOR_0;	break;
	case 2:	   res = COLOR_2;	break;
	case 4:	   res = COLOR_4;	break;
	case 8:	   res = COLOR_8;	break;
	case 16:   res = COLOR_16;	break;
	case 32:   res = COLOR_32;	break;
	case 64:   res = COLOR_64;	break;
	case 128:  res = COLOR_128;	break;
	case 256:  res = COLOR_256;	break;
	case 512:  res = COLOR_512;	break;
	case 1024: res = COLOR_1024;break;
	case 2048: res = COLOR_2048;break;
	default:break;
	}

	return res;
}

//���Ʊ��������С����
void DrawBlock(struct BG *bg)
{
	int i, j;

	for(i=1; i<=4; i++)
	for(j=1; j<=4; j++)
	{	
		setfillcolor(GetBlockColor(bg->num[i][j]));
		fillrectangle(bg->loc[i][j].x, bg->loc[i][j].y,
			bg->loc[i][j].x+bg->BKsize, bg->loc[i][j].y+bg->BKsize);
	}
}
//���Ʊ��������С�����ڵ�����
void DrawNum(struct BG *bg)
{
	int i, j;
	char str[20];
	
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(20, 0, _T("����"));

	for(i=1; i<=4; i++)
	for(j=1; j<=4; j++)
	{
		if(bg->num[i][j] != 0)
		{//����0��ʱ���û���

			RECT r = {bg->loc[i][j].x, bg->loc[i][j].y,
				bg->loc[i][j].x+bg->BKsize, bg->loc[i][j].y+bg->BKsize};
			itoa(bg->num[i][j], str, 10);

			drawtext(_T(str), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
	}
}
//ͳ��ʣ��հ�С����
int GetLastBlock(struct BG *bg)
{
	int i, j, sum = 0;

	for(i=1; i<=4; i++)
	for(j=1; j<=4; j++)
	{
		if(bg->num[i][j] == 0)
			sum++;
	}

	return sum;
}

//����ͼ��
void Draw(struct BG *bg)
{
	DrawBlock(bg);
	DrawNum(bg);
	FlushBatchDraw();

	Sleep(40);
}
