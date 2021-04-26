/*
 * main.h
 *
 *  Created on: 2021Äê1ÔÂ14ÈÕ
 *      Author: hyq
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*test option start*/
#define OFFSETOF_TEST 0
#define DEBUGFUNC_TEST 0
#define STRUCT_MEBER_TEST 0
#define PRINT_TEST_1 0
#define GETS_TEST 0
/*test option end*/

#if OFFSETOF_TEST
#define OFFSETOF(strct,elem) ((long)&(((struct strct *)0)->elem))

struct strct {
	char member_str;
	int member_int;
	void (*member_fun)(void);
};
#endif

#if STRUCT_MEBER_TEST
struct a_struct {
	char char_t;
	int  int_t;
};
struct b_struct {
	char char_t;
	int  int_t;
};
struct A_struct {
	struct a_struct a_struct_t;
	struct b_struct b_struct_t;
};
struct B_struct {
	struct a_struct a_struct_t;
	struct b_struct b_struct_t;
};
struct a_p_struct {
	char *char_t_p;
	int  *int_t_p;
};
struct b_p_struct {
	char *char_t_p;
	int  *int_t_p;
};
struct A_p_struct {
	struct a_p_struct *a_struct_t_p;
	struct b_p_struct *b_struct_t_p;
};
struct B_p_struct {
	struct a_p_struct *a_struct_t_p;
	struct b_p_struct *b_struct_t_p;
};
#endif

#if DEBUGFUNC_TEST
#if defined(__FUNCTION__)
     #define DEBUGFUNC(_Func)
#else
     #define DEBUGFUNC(_Func) static const char main[] = _Func;
#endif
#endif

#if PRINT_TEST_1
#define DRV_NAME "ide-gd"
#define PFX DRV_NAME ": "

#define WIFI_WARN_FUNC(fmt, arg...)   { printf(PFX "%s: "  fmt, __FUNCTION__ ,##arg);}
#endif

#endif /* MAIN_H_ */
