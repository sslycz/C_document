/*
 * main.c
 *
 *  Created on: 2020年11月21日
 *      Author: hyq
 */

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void scanfGet(int num[],int length)
{
#define LENGTH_SCANFGET 1000
	if(length > LENGTH_SCANFGET)
		length = LENGTH_SCANFGET;
    int i;
	for(i = 0; i < length; i++)
	{
		scanf("%d", &num[i]);
	    fflush(stdin); /*换行输入*/
	}
}
void selectSort(int num[], int length)
{
	for(int i = 0; i < length -1 ; i++)
	{
		int min = i;
		for(int j = i + 1; j < length; j++)
		{
			if(num[min] > num[j]) min = j;
		}
		int temp = num[i];
		num[i] = num[min];
		num[min] = temp;
	}
}

int main(void)
{
#if OFFSETOF_TEST
	int len;
	char dest[1024];
	char buffer[1024] = {'a','b','c'};
	strcat(dest,buffer);

	printf("dest: %s\n",dest);
	printf("buffer: %s\n",buffer);
	len=strlen(dest);
	printf("length of dest is %d\n",len);
	len=strlen(buffer);
	printf("buffer of dest is %d\n",len);
#endif

#if DEBUGFUNC_TEST
	DEBUGFUNC("xxx");
	printf("__FUNCTION__=%s\n",__FUNCTION__);
	printf("__FUNCTION__[0]=%c\n",main[0]);
#endif

#if STRUCT_MEBER_TEST
	struct A_struct A_struct_t;
	struct B_struct B_struct_t;
	B_struct_t.a_struct_t = (struct a_struct){'1',2};
	A_struct_t.a_struct_t = B_struct_t.a_struct_t;
	B_struct_t.b_struct_t.char_t = '1';
	B_struct_t.b_struct_t.int_t = 2;
	A_struct_t.b_struct_t = B_struct_t.b_struct_t;
	printf("A_struct_t.a_struct_t.char_t = %c\n",A_struct_t.a_struct_t.char_t);
	printf("A_struct_t.a_struct_t.int_t = %d\n",A_struct_t.a_struct_t.int_t);
	printf("A_struct_t.b_struct_t.char_t = %c\n",A_struct_t.b_struct_t.char_t);
	printf("A_struct_t.b_struct_t.int_t = %d\n",A_struct_t.b_struct_t.int_t);

	char a = 'a';
	struct a_p_struct b, c;

	struct A_p_struct A_p_struct_t;
	struct B_p_struct B_p_struct_t;
	struct A_p_struct * A_struct_t_p;
	struct B_p_struct * B_struct_t_p;

	A_struct_t_p = &A_p_struct_t;
	B_struct_t_p = &B_p_struct_t;
	B_struct_t_p->a_struct_t_p = &b;
	A_struct_t_p->a_struct_t_p = &c;

	B_struct_t_p->a_struct_t_p->char_t_p = &a;
	A_struct_t_p->a_struct_t_p->char_t_p = B_struct_t_p->a_struct_t_p->char_t_p;
	printf("A_struct_t_p->a_struct_t_p->char_t_p -> %c\n",*(A_struct_t_p->a_struct_t_p->char_t_p));

#endif

#if PRINT_TEST_1
	WIFI_WARN_FUNC("1st call \n");
	WIFI_WARN_FUNC("major %d minor %d (pid %d)\n",
		1U,
		2U,
		3U);
f_goto:
	printf("%s: %d\n"  , __FUNCTION__ ,1);
#endif

#if GETS_TEST
#define LENGTH 3
	char *charInput;
	char * str_prt = (char * )malloc(LENGTH*sizeof(char));
	memset(str_prt,'\0',LENGTH*sizeof(char));
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
#endif



	char charInput[4];
	int length = 0;
	int lengthRecord[100];
	int *num[100];
	int cnt = 0;
	while(1)
	{
//		gets(charInput);
//		length = atoi(charInput);
		scanf("%d",&length);
        printf("***length = %d***\n", length);
		fflush(stdout);
		if(length > 0)
		{
            lengthRecord[cnt] = length;
			num[cnt] = (int *)malloc(length*sizeof(int));
			memset(num[cnt],'\0',length*sizeof(int));
			scanfGet(num[cnt],length);
			cnt++;
		}
		else
		{
			break;
		}

	}

	for(int i = 0; i < cnt; i++)
	{
		selectSort(num[i], lengthRecord[i]);
		for(int j = 0; j < lengthRecord[i]; j++)
		{
            if(j > 0 && (*(num[i]+j) == *(num[i]+j-1)))
				continue;
			printf("%d\n",*(num[i]+j));
		}
		free(num[i]);

	}
    return 0;

}
