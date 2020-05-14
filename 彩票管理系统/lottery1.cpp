#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "header.h"

int wincode[7] = { 0,0,0,0,0,0,0, };

void sort(int a[], int n) /*������*/
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
	case 4:printf("��ϲ���������ĵȽ���\n"); break;
	case 5:printf("��ϲ�����������Ƚ���\n"); break;
	case 6:printf("��ϲ�������˶��Ƚ���\n"); break;
	case 7:printf("��ϲ��������һ�Ƚ���\n"); break;
	default:
		printf("���ź�����δ�н���\n"); break;
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
		printf("��ѡ��%dע����Ϊ��", x + 1);
		for (i = 0; i < 7; i++)
		{
			printf("%-2d ", a[i]);
		}
		printf("\n");
	}
	printf("\n");
	printf("�ȴ�������\n");
	for (i = 0; i < 10; i++)
	{
		color(6);
		printf(">");
		Sleep(200);
	}
	printf("\n\n\n");
	color(7);
	printf("�н�����Ϊ��");
	for (i = 0; i < 7; i++)
	{
		printf("%-2d ", wincode[i]);
	}
	printf("\n");
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("��%dע�н����Ϊ��", i + 1);
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
			printf("�������%dע���룺",x+1);
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
					printf("�����ظ���\n");
				}
			}
			else
			{
				index = 0;
				printf("��ΧΪ1��35��\n");
			}
		} while (1);
		b[x] = runLottery(a);
		sort(a, 7);
		printf("��ѡ��%dע����Ϊ��", x + 1);
		for (i = 0; i < 7; i++)
		{
			printf("%-2d ", a[i]);
		}
		printf("\n");
	}
	printf("\n");
	printf("�ȴ�������\n");
	for (i = 0; i < 10; i++)
	{
		color(6);
		printf(">");
		Sleep(200);
	}
	printf("\n\n\n");
	color(7);
	printf("�н�����Ϊ��");
	for (i = 0; i < 7; i++)
	{
		printf("%-2d ", wincode[i]);
	}
	printf("\n");
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("��%dע�н����Ϊ��", i + 1);
		win(b[i]);
	}
}

void lottery_1()
{
	char index;
	do {
		printf("��ѡ�밴1����ѡ�밴2����0������ҳ��");
		scanf("%d", &index);
		if (index == 1)
		{
			char n;
			printf("�������ѡע��1-5��");
			scanf("%d", &n);
			system("cls");
			lottery_1_j(n);
		}
		else if (index == 2)
		{
			char n;
			printf("��������ѡע��1-5��");
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
			printf("��������������룺\n");
		}
	} while (1);

}