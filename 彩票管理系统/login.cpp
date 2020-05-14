#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "header.h"

typedef struct {
	char name[10];	//登录名
	char password[7];	//密码
}user;

int isPassWord(user user1)
{
	user b;
	FILE* fp;	//文件指针
	if (!(fp = fopen("user.txt", "r+"))) 
	{
		printf("文件打开失败！");
		exit(0);
	}
	while (!feof(fp))
	{
		fread(&b, sizeof(user), 1, fp);
		if (!strcmp(b.name, user1.name)) {
			if (!strcmp(b.password, user1.password))
			{
				fclose(fp);
				return 1;
			}
		}
	}
	fclose(fp);
	return 0;
}

void HideCursor(int index)		//隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, index }; //1表示显示 0表示隐藏
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void login()
{
	int i;

	HideCursor(0);
	printf("即将登陆，请稍后");
	for (i = 0; i < 3; i++)
	{

		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(100);
		printf("\b\b\b");
		Sleep(100);
		printf("   ");
		Sleep(100);
		printf("\b\b\b");
		Sleep(100);
	}
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	HideCursor(1);
}

void lottery()
{
	int n;
	system("cls");
	printf("选择彩票玩法：\n");
	printf("0.退出\n");
	printf("1.35选7\n");
	printf("2.双色球\n");
	printf("输入对应操作：");
	scanf("%d", &n);
	if (n == 1)
	{
		lottery_1();
	}
	else if (n == 2)
	{
		lottery_2();
	}
	else if (n == 0)
	{
		exit(0);
	}
	else {
		printf("请输入正确序号！");
		Sleep(1000);
		system("cls");
		lottery();
	}
}

void userLogin()
{
	int ch;
	user a;	//用户a
	char password2[7];	//确认密码

	do {
		printf("请输入用户名：");
		scanf("%s", &a.name);
		while ((ch = getchar()) != EOF && ch != '\n')
			;
		if (!isName(a.name))	//用户名是否存在
		{
			do {
				int i;
				printf("请输入6位密码：");
				for (i = 0; i < 6; i++)
				{
					a.password[i] = getch();
					printf("*");
				}
				printf("\n");
				a.password[6] = '\0';
				if (isPassWord(a))
				{
					login();
					system("cls");
					lottery();
				}
				else
				{
					printf("密码输入错误！\n");
				}
			} while (1);
			break;
		}
		else
		{
			printf("用户名不存在！\n");
		}
	} while (1);
}