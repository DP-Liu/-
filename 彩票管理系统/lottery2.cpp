#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "header.h"

int code[7] = { 0,0,0,0,0,0,0, };

void sort2(int a[], int n)
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

void win2(int n)
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

void runLottery2()
{
	int i, j;
	srand((unsigned)time(NULL));
	for (i = 0; i < 6; i++)
	{
		int num;
		j = 0;
		while (j != 6)
		{
			num = rand() % 33 + 1;
			for (j = 0; j < 6; j++)
			{
				if (code[j] == num)
					break;
			}
		}
		code[i] = num;
	}
	code[6] = rand() % 15 + 1;

	sort2(code, 6);
}

void show(int a[])
{
	int i;
	color(4);
	for (i = 0; i < 6; i++)
	{
		printf("%-2d ", a[i]);
	}
	color(1);
	printf("%-2d ", a[6]);
}

int runLottery_2(const int b[])
{
	int i, j, index = 0;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (code[j] == b[i])
			{
				index++;
			}
		}
	}
	return index;
}

void lottery_2_z(char n)
{
	int index = 0;
	int i, j, x;
	int b[5];
	int a[7] = { 0,0,0,0,0,0,0 };
	runLottery2();
	for (x = 0; x < n; x++)
	{
		do {
			printf("请输入第%d注号码：", x + 1);
			scanf("%d %d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]);
			for (i = 0; i < 6; i++)
			{
				if (a[i] < 1 || a[i] > 35)
				{
					index = 1;
				}
			}
			if (a[6] < 1 || a[6] > 15)
			{
				index = 1;
			}
			if (index != 1)
			{
				index = 0;
				for (i = 0; i < 6; i++)
				{
					for (j = i + 1; j < 6; j++)
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
				printf("红色球范围为1到35，蓝色球范围为1到15！\n");
			}
		} while (1);
		b[x] = runLottery_2(a);
		sort2(a, 6);
		printf("自选第%d注号码为：", x + 1);
		show(a);
		color(7);
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
	show(code);
	color(7);
	printf("\n");
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("第%d注中奖结果为：", i + 1);
		win2(b[i]);
	}
}

void lottery_2_j(char n)
{
	int i, j, x;
	int a[7];
	int b[5];
	runLottery2();
	for (x = 0; x < n; x++)
	{
		for (i = 0; i < 6; i++)
		{
			int num;
			j = 0;
			while (j != 6)
			{
				num = rand() % 33 + 1;
				for (j = 0; j < 6; j++)
				{
					if (a[j] == num)
						break;
				}
			}
			a[i] = num;
		}
		a[6] = rand() % 15 + 1;
		sort2(a, 6);
		b[x] = runLottery_2(a);
		printf("机选第%d注号码为：", x + 1);
		show(a);
		color(7);
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
	show(code);
	printf("\n");
	printf("\n");
	color(7);
	for (i = 0; i < n; i++)
	{
		printf("第%d注中奖结果为：", i + 1);
		win2(b[i]);
	}
}


void lottery_2()
{
	int a[] = { 11,24,31,41,55,61,74 };
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
			lottery_2_j(n);
		}
		else if (index == 2)
		{
			char n;
			printf("请输入自选注数1-5：");
			scanf("%d", &n);
			system("cls");
			lottery_2_z(n);
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