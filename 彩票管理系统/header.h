#pragma once


/* page.cpp */
void gotoxy(int x, int y);	//设置光标
int color(int c);	//设置文字颜色

/* register.cpp */
void userRegister();	//用户注册
int isForbiddenChar(const char const* name);	//是否存在非法字符
int isName(const char const* name);		//用户名是否存在
void userLogin();

/* game.cpp */
void lottery_1();
void lottery_2();
void lottery();
void homePage();