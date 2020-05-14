#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct {
	char name[10];	//��¼��
	char password[7];	//����
}user;

/* *
* ��������isName
* ���ã��ж��û����Ƿ����
* ���ڷ���0
* �����ڷ���1
*/
int isName(const char const* name)
{
	user b;
	FILE* fp;	//�ļ�ָ��
	if (!(fp = fopen("user.txt", "r+"))
		) {
		printf("�ļ���ʧ�ܣ�");
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
* ��������printUser
* ���ã������û���������
*/
int printUser(const user p)
{
	FILE* fp;	//�ļ�ָ��
	if (!(fp = fopen("user.txt", "a+"))
		) {
		printf("�ļ���ʧ�ܣ�");
		exit(0);
	}
	fwrite(&p, sizeof(user), 1, fp);
	fclose(fp);
}

/* *
* ��������isForbiddenChar
* ���ã��ж��Ƿ��зǷ��ַ�
* ���з���1
* �޷���0
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
* ��������userRegister
* ���ã��û�ע��
*/
void userRegister()
{
	int ch;
	user a;	//�û�a
	char password2[7];	//ȷ������

	do {
		printf("�������û�����");
		scanf("%s", &a.name);
		while ((ch = getchar()) != EOF && ch != '\n')
			;
		if (isName(a.name))	//�û����Ƿ����
		{
			if (6 <= strlen(a.name) && strlen(a.name) <= 10)	//�û��������Ƿ�Ϊ6��10
			{
				if (!isForbiddenChar(a.name))	//�û����Ƿ��зǷ��ַ�
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
						if (!isForbiddenChar(a.password))		//�����Ƿ��зǷ��ַ�
						{
							printf("������ȷ�����룺");
							for (i = 0; i < 6; i++)
							{
								password2[i] = getch();
								printf("*");
							}
							printf("\n");
							password2[6] = '\0';
							if (!strcmp(a.password, password2))		//���������Ƿ���ͬ
							{
								for (i = 0; i < 25; i++)
								{
									printf(">");
									Sleep(50);
								}
								printf("\n");
								printf("ע��ɹ���\n");
								printUser(a);
								break;
							}
							else {
								printf("�������벻һ����\n");
							}
						}
						else
						{
							printf("���зǷ��ַ���\n");
						}
					} while (1);
					break;
				}
				else {
					printf("���зǷ��ַ���\n");
				}

			}
			else
			{
				printf("�û�������Ϊ6��10λ��\n");
			}

		}
		else {
			printf("�û����Ѵ��ڣ�\n");
		}
		Sleep(1000);
		system("cls");
	} while (1);
}

