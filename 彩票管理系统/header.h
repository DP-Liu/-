#pragma once


/* page.cpp */
void gotoxy(int x, int y);	//���ù��
int color(int c);	//����������ɫ

/* register.cpp */
void userRegister();	//�û�ע��
int isForbiddenChar(const char const* name);	//�Ƿ���ڷǷ��ַ�
int isName(const char const* name);		//�û����Ƿ����
void userLogin();

/* game.cpp */
void lottery_1();
void lottery_2();
void lottery();
void homePage();