#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "header.h"

typedef struct {
	char name[10];	//��¼��
	char password[7];	//����
}user;

int isPassWord(user user1)
{
	user b;
	FILE* fp;	//�ļ�ָ��
	if (!(fp = fopen("user.txt", "r+"))) 
	{
		printf("�ļ���ʧ�ܣ�");
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

void HideCursor(int index)		//���ع��
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, index }; //1��ʾ��ʾ 0��ʾ����
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void login()
{
	int i;

	HideCursor(0);
	printf("������½�����Ժ�");
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
	printf("ѡ���Ʊ�淨��\n");
	printf("0.�˳�\n");
	printf("1.35ѡ7\n");
	printf("2.˫ɫ��\n");
	printf("�����Ӧ������");
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
		printf("��������ȷ��ţ�");
		Sleep(1000);
		system("cls");
		lottery();
	}
}

void userLogin()
{
	int ch;
	user a;	//�û�a
	char password2[7];	//ȷ������

	do {
		printf("�������û�����");
		scanf("%s", &a.name);
		while ((ch = getchar()) != EOF && ch != '\n')
			;
		if (!isName(a.name))	//�û����Ƿ����
		{
			do {
				int i;
				printf("������6λ���룺");
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
					printf("�����������\n");
				}
			} while (1);
			break;
		}
		else
		{
			printf("�û��������ڣ�\n");
		}
	} while (1);
}