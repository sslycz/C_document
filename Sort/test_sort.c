/*
 * test.c
 *
 *  Created on: 2021年2月22日
 *      Author: hyq
 */
#include "test_sort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"


void sortTest(void)
{
#define LENGTH 11
	int num[LENGTH];
	int i;

	srand((unsigned)time(NULL));
	for(i = 0; i < LENGTH; i++)
	{
		num[i] =  rand()%1000;
	}
	printf("排序前：\n");
	for(i = 0; i < LENGTH; i++)
	{
		printf("num[%d] = %d\n", i, num[i]);
	}
//	selectSort(num, LENGTH);//选择排序
//	insertSort(num, LENGTH);//插入排序
	bubbleSort(num, LENGTH);//冒泡排序
	printf("排序后：\n");
	for(i = 0; i < LENGTH; i++)
	{
		printf("num[%d] = %d\n", i, num[i]);
	}
}
