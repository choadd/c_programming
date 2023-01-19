#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int level;
int arrayFish[6];
int * cursor;

void initData();
void printfFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();


int main()
{
	long startTime = 0;
	long totalElapsedTime = 0;
	long prevElapsedTime = 0;

	int num;
	initData();

	cursor = arrayFish;

	startTime = clock();
	while (1)
	{
		printfFishes();
		printf("몇번 어항에 물을 넣을까? ");
		scanf_s(" %d ", &num);

		if (num < 1 || num > 6)
		{
			printf("\n입력값이 잘못 되었다.\n");
			continue;
		}

		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("총 경과 시간 : %d\n", totalElapsedTime);

		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("최근 경과 시간 : %1d sec \n", prevElapsedTime);

		decreaseWater(prevElapsedTime);

		if (cursor[num - 1] <= 0)
		{
			printf("%d 번 물고기는 죽었습니다.\n", num);
		}
		else if (cursor[num - 1] + 1)
		{
			printf("%d 번 어항에 물을 준다.\n", num);
			cursor[num - 1] += 1;
		}

		if (totalElapsedTime / 20 > level - 1)
		{
			level++;
			printf("레벨 업 %d 에서 %d로 레벨업\n", level - 1, level);

			if (level == 5) 
			{
				printf("축하합니다 최고레벨 입니다.\n");
				exit(0);
			}
		}
		if (checkFishAlive() == 0)
		{
			printf("물고기 0마리 게임 끝");
			exit(0);
		}
		else
		{
			printf("물고기 아직 살아있음.");
		}

	}

	prevElapsedTime = totalElapsedTime;

	
	return 0;
}

void initData()
{
	level = 1;
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100;
	}
}

void printfFishes()
{
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++)
	{
		printf(" %4d ", arrayFish[i]);
	}
	printf("\n\n");
}

void decreaseWater(long elapsedTime)
{
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] -= (level * 3 * (int)elapsedTime);
		if (arrayFish < 0)
		{
			arrayFish[i] = 0;
		}
	}
}
int checkFishAlive()
{
	for (int i = 0; i < 6; i++)
	{
		if (arrayFish[i] > 0)
			return 1;
	}
}