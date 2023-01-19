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
		printf("��� ���׿� ���� ������? ");
		scanf_s(" %d ", &num);

		if (num < 1 || num > 6)
		{
			printf("\n�Է°��� �߸� �Ǿ���.\n");
			continue;
		}

		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("�� ��� �ð� : %d\n", totalElapsedTime);

		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("�ֱ� ��� �ð� : %1d sec \n", prevElapsedTime);

		decreaseWater(prevElapsedTime);

		if (cursor[num - 1] <= 0)
		{
			printf("%d �� ������ �׾����ϴ�.\n", num);
		}
		else if (cursor[num - 1] + 1)
		{
			printf("%d �� ���׿� ���� �ش�.\n", num);
			cursor[num - 1] += 1;
		}

		if (totalElapsedTime / 20 > level - 1)
		{
			level++;
			printf("���� �� %d ���� %d�� ������\n", level - 1, level);

			if (level == 5) 
			{
				printf("�����մϴ� �ְ��� �Դϴ�.\n");
				exit(0);
			}
		}
		if (checkFishAlive() == 0)
		{
			printf("����� 0���� ���� ��");
			exit(0);
		}
		else
		{
			printf("����� ���� �������.");
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
	printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6);
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