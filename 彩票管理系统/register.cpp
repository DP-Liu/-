#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct {
	char name[10];	//登录名
	char password[7];	//密码
}user;

/* *
* 函数名：isName
* 作用：判断用户名是否存在
* 存在返回0
* 不存在返回1
*/
int isName(const char const* name)
{
	user b;
	FILE* fp;	//文件指针
	if (!(fp = fopen("user.txt", "r+"))
		) {
		printf("文件打开失败！");
		exit(0);
	}
	while (!feof(fp))
	{
		fread(&b, sizeof(user), 1, fp);
		if (!strcmp(b.name, name)) {
			fclose(fp);
			return 0;
		}
	}
	fclose(fp);
	return 1;
}

/* *
* 函数名：printUser
* 作用：储存用户名及密码
*/
int printUser(const user p)
{
	FILE* fp;	//文件指针
	if (!(fp = fopen("user.txt", "a+"))
		) {
		printf("文件打开失败！");
		exit(0);
	}
	fwrite(&p, sizeof(user), 1, fp);
	fclose(fp);
}

/* *
* 函数名：isForbiddenChar
* 作用：判断是否含有非法字符
* 含有返回1
* 无返回0
*/
int isForbiddenChar(const char const* name)
{
	int i;
	for (i = 0; i < strlen(name); i++)
	{
		if ('A' <= name[i] && name[i] <= 'Z');
		else if ('a' <= name[i] && name[i] <= 'z');
		else if ('0' <= name[i] && name[i] <= '9');
		else {
			return 1;
		}
	}
	return 0;
}

/* *
* 函数名：userRegister
* 作用：用户注册
*/
void userRegister()
{
	int ch;
	user a;	//用户a
	char password2[7];	//确认密码

	do {
		printf("请输入用户名：");
		scanf("%s", &a.name);
		while ((ch = getchar()) != EOF && ch != '\n')
			;
		if (isName(a.name))	//用户名是否存在
		{
			if (6 <= strlen(a.name) && strlen(a.name) <= 10)	//用户名长度是否为6到10
			{
				if (!isForbiddenChar(a.name))	//用户名是否含有非法字符
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
						if (!isForbiddenChar(a.password))		//密码是否含有非法字符
						{
							printf("请输入确认密码：");
							for (i = 0; i < 6; i++)
							{
								password2[i] = getch();
								printf("*");
							}
							printf("\n");
							password2[6] = '\0';
							if (!strcmp(a.password, password2))		//两次密码是否相同
							{
								for (i = 0; i < 25; i++)
								{
									printf(">");
									Sleep(50);
								}
								printf("\n");
								printf("注册成功！\n");
								printUser(a);
								break;
							}
							else {
								printf("两次密码不一样！\n");
							}
						}
						else
						{
							printf("含有非法字符！\n");
						}
					} while (1);
					break;
				}
				else {
					printf("含有非法字符！\n");
				}

			}
			else
			{
				printf("用户名长度为6到10位！\n");
			}

		}
		else {
			printf("用户名已存在！\n");
		}
		Sleep(1000);
		system("cls");
	} while (1);
}

