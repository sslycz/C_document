/*
 * main.c
 *
 *  Created on: 2020Äê7ÔÂ20ÈÕ
 *      Author: huang.yiqiang
 */
#include <stdio.h>
#include "main.h"

int main(void)
{

	int data[10] = { [0]=1,[9]=2,[1 ...6] = 3};
	printf("%s %s\n", __FUNCTION__, __func__);
	for(int i = 0; i < sizeof(data)/sizeof(int); i++)
	{
		printf("data[%d] = %d\n", i,data[i]);
	}
	fflush(stdout);

    return 0;
}
