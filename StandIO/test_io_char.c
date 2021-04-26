/*
 * test_io_char.c
 *
 *  Created on: 2021年2月23日
 *      Author: hyq
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io_char.h"
#include "../Sort/sort.h"


/*****************************
 *
 *
 *
 ******************************/
void getInput(void)
{
#if 1
	char charInput[4];
	int length = 0;
	int *num[100];
	int cnt = 0;
	while(1)
	{
		gets(charInput);
		length = atoi(charInput);
//		printf("length = %d\n", length);
		fflush(stdout);
		if(length > 0)
		{
			num[cnt] = (int *)malloc(length*sizeof(int));
			memset(num[cnt],'\0',length*sizeof(int));
			scanfGet(num[cnt],length);
			cnt++;
		}
		else
		{
//			printf("end input\n");
//			fflush(stdout);
			break;
		}

	}
#else
	int length = 0;
	int *num[100];
	int cnt = 0;
	int lengthRecord[100];
	printf("please set length: \n");
	fflush(stdout);
	while(scanf("%d",&length)!=EOF)
	{
        lengthRecord[cnt] = length;
    	printf("length=%d \n", length);
    	fflush(stdout);
		num[cnt] = (int *)malloc(length*sizeof(int));
		memset(num[cnt],'\0',length*sizeof(int));
		scanfGet(num[cnt],lengthRecord[cnt]);
		cnt++;
	}
#endif

	for(int i = 0; i < cnt; i++)
	{
		selectSort(num[i], _msize(num[i])/sizeof(int));
//		printf("第%d组：%d个元素\n", i+1, (int)(_msize(num[i])/sizeof(int)));
		for(int j = 0; j < _msize(num[i])/sizeof(int); j++)
		{

			if(j > 0 && (*(num[i]+j) == *(num[i]+j-1)))
				continue;
			printf("%d\n",*(num[i]+j));
		}
		free(num[i]);

	}


}
