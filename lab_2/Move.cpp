#include "Move.h"

#include <conio.h>
#include <stdlib.h>

DIRECTION NextDirection()
{
	DIRECTION nextDir = NOTTRUEDIR;
	//如果有键盘信息
	if (kbhit())
	{
		char ch = getch();

		if (ch == 'w' || ch == 'W')
			nextDir = DIR_UP;
		else if (ch == 's' || ch == 'S')
			nextDir = DIR_DOWN;
		else if (ch == 'a' || ch == 'A')
			nextDir = DIR_LEFT;
		else if (ch == 'd' || ch == 'D')
			nextDir = DIR_RIGHT;

		//如果是小键盘信息
		if (ch == (char)0xE0 || ch == 0)
		{
			ch = getch();

			if (ch == 72)
				nextDir = DIR_UP;
			else if (ch == 80)
				nextDir = DIR_DOWN;
			else if (ch == 75)
				nextDir = DIR_LEFT;
			else if (ch == 77)
				nextDir = DIR_RIGHT;
		}
	}
	 
	
	return nextDir;
}
void ClearKbhit()
{
	while(kbhit())
		getch();
}
void Move(struct BG *bg, DIRECTION direction)
{
	switch(direction)
	{
	case DIR_UP:
		MoveUp(bg);
		break;
	case DIR_DOWN:
		MoveDown(bg);
		break;
	case DIR_LEFT:
		MoveLeft(bg);
		break;
	case DIR_RIGHT:
		MoveRight(bg);
		break;
	default:
		break;
	}
}
void MoveUp(struct BG *bg)
{
	int i, j;

	for(i=1; i<=3; i++)
	for(j=1; j<=4; j++)
	{
		if (bg->num[i][j] == bg->num[i+1][j] && !bg->visit[i][j] && !bg->visit[i+1][j] || bg->num[i][j] == 0)
		{
			if(bg->num[i][j] == bg->num[i+1][j] && bg->num[i][j])
				bg->visit[i][j] = 1;

			bg->num[i][j] += bg->num[i+1][j];
			bg->num[i+1][j] = 0;
		}
	}
}
void MoveDown(struct BG *bg)
{
	int i, j;
	
	for(i=4; i>=2; i--)
	for(j=1; j<=4; j++)
	{
		if (bg->num[i][j] == bg->num[i-1][j] && !bg->visit[i][j] && !bg->visit[i-1][j] ||bg->num[i][j] == 0)
		{
			if(bg->num[i][j] == bg->num[i-1][j] && bg->num[i][j])
				bg->visit[i][j] = 1;

			bg->num[i][j] += bg->num[i-1][j];
			bg->num[i-1][j] = 0;
		}
	}
}
void MoveLeft(struct BG *bg)
{
	int i, j;
	
	for(i=1; i<=3; i++)
	for(j=1; j<=4; j++)
	{
		if (bg->num[j][i] == bg->num[j][i+1] && !bg->visit[j][i] && !bg->visit[j][i+1] || bg->num[j][i] == 0)
		{

			if(bg->num[j][i] == bg->num[j][i+1] && bg->num[j][i])
				bg->visit[j][i] = 1;
			
			bg->num[j][i] += bg->num[j][i+1];
			bg->num[j][i+1] = 0;
		}
	}
}
void MoveRight(struct BG *bg)
{
	int i, j;
	
	for(i=4; i>=2; i--)
	for(j=1; j<=4; j++)
	{
		if (bg->num[j][i] == bg->num[j][i-1] && !bg->visit[j][i] && !bg->visit[j][i-1] || bg->num[j][i] == 0)
		{

			if(bg->num[j][i] == bg->num[j][i-1] && bg->num[j][i])
				bg->visit[j][i] = 1;

			bg->num[j][i] += bg->num[j][i-1];
			bg->num[j][i-1] = 0;

		}
	}
}