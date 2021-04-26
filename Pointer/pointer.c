/*
 * pointer.c
 *
 *  Created on: 2021��4��17��
 *      Author: hyq
 *
 */

/*
 * ���Խṹ��ָ�붨�������δ��ʼ��ʱ��ֵ
 */

#include <stdio.h>

#include "pointer.h"

struct stru
{
	uint32 val;
	uint32 key;
	struct stru * next;
};

void pointer_defined_test()
{
	struct stru * sp;
	struct stru struVal;
//	printf("&sp: 0x%x *sp: 0x%x\n", &sp, sp->key);
//	printf("sp: 0x%x &sp: 0x%x *sp: 0x%x\n", sp, &sp, (uint32)*sp);
	if(sp == NULL)
	{
		printf("sp = NULL\n");
		fflush(stdout);

	}
	sp = &struVal;
	struVal.val = 0x12345678;
	struVal.key = 0xaabbccdd;
	printf("struVal.key: 0x%x struVal.next: 0x%x struVal.val: 0x%x\n", struVal.key, struVal.next, struVal.val);
	printf("sp: 0x%x &sp: 0x%x *sp: 0x%x\n", sp, &sp, sp->key);
	(&struVal)->val = 1;
	fflush(stdout);
}

