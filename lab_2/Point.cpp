#include "Point.h"
#include "BackGround.h"

#include <stdlib.h>

//获取一个随机空白的小方块的坐标
struct location GetOnePoint(struct BG *bg)
{
	int i, j, k;
	struct location res ={0};

	k = GetLastBlock(bg);

	if(k == 0)
		return res;
	k = rand() % k + 1;

	for(i=1; i<=4 && k; i++)
	for(j=1; j<=4 && k; j++)
	{
		if(bg->num[i][j] == 0)
			k--;
		if(k == 0)
		{
			res.x = i;
			res.y = j;
		}
	}

	return res;
}
//获取一个随机值，2或者4
int GetOneNum()
{
	if(rand() % 2)
		return 2;
	return 4;
}
//给一个空白的小方块设置一个随机值,设置成功返回1， 否则返回0
int SetOneNum(struct BG *bg)
{
	struct location p = GetOnePoint(bg);
	
	if (p.x == 0 && p.y == 0)
		return 0;

	bg->num[p.x][p.y] = GetOneNum();

	return 1;
}
