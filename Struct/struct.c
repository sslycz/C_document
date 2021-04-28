/*
 * struct.c
 *
 *  Created on: 2021Äê4ÔÂ27ÈÕ
 *      Author: hyq
 */
#include <stdio.h>

struct strc{
	char str[10];
	int a;
	int b;
};

static struct strc  struct_array[] = {
		{
				.str = "test1",
				.b = 2,
				.a = 1,
		},
		{
				.a = 3,
				.b = 4,
				.str = "test2",
		}

};

void struct_test(void)
{
	printf("addr:  0x%x, 0x%x\n", &struct_array[0], &struct_array[1]);
	printf("->str: %s, %s\n", struct_array[0].str, struct_array[1].str);
	printf("->a:   %d, %d\n", struct_array[0].a, struct_array[1].a);
	printf("->b:   %d, %d\n", struct_array[0].b, struct_array[1].b);
}
