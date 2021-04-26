/*
 * io_char.c
 *
 *  Created on: 2021年2月22日
 *      Author: hyq
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io_char.h"

/*****************************
 * gets()
 *
 *
 ******************************/
void getsTest(void)
{
#define LENGTH_GETSTEST 3
	char string[LENGTH_GETSTEST];
	char *charInput = string;
	char *str_prt = (char * )malloc(LENGTH_GETSTEST*sizeof(char));
	memset(str_prt,'\0',LENGTH_GETSTEST*sizeof(char));
	if(str_prt != NULL)
	{
		if(strlen(str_prt) == 0)
		{
			printf("string is empty\n");
		}
	}
	printf("please input char:\n");
	fflush(stdout);
//	*str_prt = getchar();
	gets(charInput);
	printf("charInput is:");
	puts(charInput);
	printf("\n");

	str_prt = charInput;

	if(str_prt != NULL)
	{
		if(strlen(str_prt) == 0)
		{
			printf("string is empty\n");
		}
		else
		{
			printf("str_prt is:");
			puts(str_prt);
			printf("\n");
			printf("*str_prt = %s\n", str_prt);
		}
	}
}

/*****************************
 *
 *
 *
 ******************************/
void scanfTest(void)
{
    int c = 0;
    char a,d;

	printf("please input: \n");
	fflush(stdout);
    printf("scanf() got %d vars\n",scanf("%d %c", &c, &d));
    fflush(stdin);
    printf("scanf() got %d vars\n",scanf("%c", &a));
    printf("c = %d, d=%c\n", c,d);
    printf("a = %c\n", a);
}

/*****************************
 *
 *
 *
 ******************************/
void scanfGet(int num[],int length)
{
    int i;

	for(i = 0; i < length; i++)
	{
		scanf("%d", &num[i]);
	    fflush(stdin); /*换行输入*/
	}

//	for(i = 0; i < length; i++)
//	{
//		printf("num[%d] = %d\n", i, num[i]);
//		fflush(stdout);
//	}
}
