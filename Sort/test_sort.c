/*
 * test.c
 *
 *  Created on: 2021��2��22��
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
	printf("����ǰ��\n");
	for(i = 0; i < LENGTH; i++)
	{
		printf("num[%d] = %d\n", i, num[i]);
	}
//	selectSort(num, LENGTH);//ѡ������
//	insertSort(num, LENGTH);//��������
	bubbleSort(num, LENGTH);//ð������
	printf("�����\n");
	for(i = 0; i < LENGTH; i++)
	{
		printf("num[%d] = %d\n", i, num[i]);
	}
}
