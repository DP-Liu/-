#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
	int index;
	homePage();
	scanf("%d",&index);
	system("cls");
	if (index == 1)
	{
		userRegister();
		system("cls");
		printf("登录：\n\n");
		userLogin();
	}
	else if (index == 2)
	{
		printf("登录：\n\n");
		userLogin();
	}
	system("pause>nul");
	return 0;
}