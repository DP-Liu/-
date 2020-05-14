#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "header.h"

int wincode[7] = { 0,0,0,0,0,0,0, };

void sort(int a[], int n) /*排序函数*/
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
}

void win(int n)
{
	switch (n)
	{
	case 4:printf("恭喜您，中了四等奖！\n"); break;
	case 5:printf("恭喜您，中了三等奖！\n"); break;
	case 6:printf("恭喜您，中了二等奖！\n"); break;
	case 7:printf("恭喜您，中了一等奖！\n"); break;
	default:
		printf("很遗憾，您未中奖！\n"); break;
	}
}

void runLottery1()
{
	int i, j;
	srand((unsigned)time(NULL));
	for (i = 0; i < 7; i++)
	{
		int num;
		j = 0;
		while (j != 7)
		{
			num = rand() % 35 + 1;
			for (j = 0; j < 7; j++)
			{
				if (wincode[j] == num)
					break;
			}
		}
		wincode[i] = num;
	}
	sort(wincode, 7);
}

int runLottery(const int b[])
{
	int i, j, index = 0;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (wincode[j] == b[i])
			{
				index++;
			}
		}
	}
	return index;
}


void lottery_1_j(char n)
{
	int i, j, x;
	int b[5];
	int a[7] = { 0,0,0,0,0,0,0 };
	runLottery1();
	//srand((unsigned)time(NULL));
	for (x = 0; x < n; x++)
	{
		for (i = 0; i < 7; i++)
		{
			int num;
			j = 0;
			while (j != 7)
			{
				num = rand() % 35 + 1;
				for (j = 0; j < 7; j++)
				{
					if (a[j] == num)
						break;
				}
			}
			a[i] = num;
		}
		b[x] = runLottery(a);
		sort(a, 7);
		printf("机选第%d注号码为：", x + 1);
		for (i = 0; i < 7; i++)
		{
			printf("%-2d ", a[i]);
		}
		printf("\n");
	}
	printf("\n");
	printf("等待开奖：\n");
	for (i = 0; i < 10; i++)
	{
		color(6);
		printf(">");
		Sleep(200);
	}
	printf("\n\n\n");
	color(7);
	printf("中奖号码为：");
	for (i = 0; i < 7; i++)
	{
		printf("%-2d ", wincode[i]);
	}
	printf("\n");
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("第%d注中奖结果为：", i + 1);
		win(b[i]);
	}
}

void lottery_1_z(char n)
{
	int index = 0;
	int i, j, x;
	int b[5];
	int a[7] = { 0,0,0,0,0,0,0 };
	runLottery1();
	for (x = 0; x < n; x++)
	{
		do {
			printf("请输入第%d注号码：",x+1);
			scanf("%d %d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]);
			for (i = 0; i < 7; i++)
			{
				if (a[i] < 1 || a[i] > 35)
				{
					index = 1;
				}
			}
			if (index!=1)
			{
				index = 0;
				for (i = 0; i < 7; i++)
				{
					for (j = i+1; j < 7; j++)
					{
						if (a[i] == a[j])
							index = 1;
					}
				}
				if (index != 1)
				{
					index = 0;
					break;
				}
				else
				{
					index = 0;
					printf("数字重复！\n");
				}
			}
			else
			{
				index = 0;
				printf("范围为1到35！\n");
			}
		} while (1);
		b[x] = runLottery(a);
		sort(a, 7);
		printf("自选第%d注号码为：", x + 1);
		for (i = 0; i < 7; i++)
		{
			printf("%-2d ", a[i]);
		}
		printf("\n");
	}
	printf("\n");
	printf("等待开奖：\n");
	for (i = 0; i < 10; i++)
	{
		color(6);
		printf(">");
		Sleep(200);
	}
	printf("\n\n\n");
	color(7);
	printf("中奖号码为：");
	for (i = 0; i < 7; i++)
	{
		printf("%-2d ", wincode[i]);
	}
	printf("\n");
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("第%d注中奖结果为：", i + 1);
		win(b[i]);
	}
}

void lottery_1()
{
	char index;
	do {
		printf("机选请按1，自选请按2，按0返回首页：");
		scanf("%d", &index);
		if (index == 1)
		{
			char n;
			printf("请输入机选注数1-5：");
			scanf("%d", &n);
			system("cls");
			lottery_1_j(n);
		}
		else if (index == 2)
		{
			char n;
			printf("请输入自选注数1-5：");
			scanf("%d", &n);
			system("cls");
			lottery_1_z(n);
		}
		else if (index == 0)
		{
			lottery();
		}
		else
		{
			printf("输入错误，重新输入：\n");
		}
	} while (1);

}