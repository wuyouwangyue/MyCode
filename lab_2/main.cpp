#include <stdio.h>
#include <string.h>
#include <graphics.h>

#include "BackGround.h"
#include "Move.h"
#include "Point.h"

int main()
{
	struct BG bg = {400, 90};

	InIt(&bg);
	

	while(1)
	{
		DIRECTION nextDir = NextDirection();

		if (nextDir != NOTTRUEDIR)
		{
			memset(bg.visit, 0, sizeof(bg.visit));
			for(int i=0; i<3; i++)
			{
				Move(&bg, nextDir);
				Draw(&bg);
			}

			if(SetOneNum(&bg) == 0)
				break;
			Draw(&bg);
			ClearKbhit();
		}
	}
	
	EndBatchDraw();
	closegraph();
	printf("Game Over\n");
	getchar();

	return 0;
}