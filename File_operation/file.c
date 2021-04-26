/*
 * file.c
 *
 *  Created on: 2021��2��27��
 *      Author: hyq
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 1024

void fileTest(void)
{
	FILE *fp;
	fp=fopen("test1.txt","a+");
	if( fp == NULL)
	{
		printf("file cannot open \n");
	}
    else
        printf("file opened for writing \n");

//	char buf[] = "Hello, World!";
//	fwrite(buf, 1, strlen(buf), fp);

   char ch[100];
   int num;
   int i=0;

#if 0
   while (!feof(fp))
   {
	   fscanf(fp, "%c", &ch[i]);
	   printf("%c",ch[i]);
	   i++;
	   fflush(stdout);
   }
#else
   char buf[MAX_LINE];  /*������*/

//   printf("������\n");
//   for(int i = 0; i < 100; i++)
//   {
//	   if(numCheck(i))
//		   printf("%d ", i);
//   }
//   printf("\n");

   int len;             /*���ַ�����*/
   while(fgets(buf,MAX_LINE,fp) != NULL)
   {
	   len = strlen(buf);
	   buf[len-1] = '\0';  /*ȥ�����з�*/
	   printf("%s\n",buf);
   }
#endif

    if(fclose(fp)!=0)
        printf("file cannot be closed \n");
    else
        printf("file is now closed \n");

}
