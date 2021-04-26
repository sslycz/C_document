

/*****************************
 * �����1����ƿ����ˮ
 * �Ż��㣺��ѧ�������򻯼���
 *
 *
 *****************************/
#include <stdio.h>
#include <stdlib.h>

int calculate(int numEmpty)
{
    int cnt;
    if(numEmpty < 2){
        return 0;
    }else if(numEmpty == 2 || numEmpty == 3){
        return 1;
    }else{
        cnt = numEmpty/3;
        return calculate(cnt + numEmpty%3) + cnt;
    }
}

void test(void)
{
    char stringInput[11][3];
    int numEmpty = 0;
    int numGet[10] = {0};
    int i;

    //printf("please input the number of empty glasses:\n");
    for(i = 0; i < 11; i++){
        gets(stringInput[i]);
        numEmpty = atoi(stringInput[i]);
        if(0 == numEmpty){
            //printf("end input!");
            break;
        }
        numGet[i] = calculate(numEmpty);
    }
    for(int j = 0; j < i; j++){
        printf("%d\n",numGet[j]);
    }
}
/*****************************
 * �����2�������������
 * �Ż��㣺�������飬���ȥ������
 * �������⣺MinGW GCC ��
 *
 *****************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void scanfGet(int num[],int length)
{
	for(int i = 0; i < length; i++)
	{
		scanf("%d", &num[i]);
	    fflush(stdin); /*��������*/
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
	char charInput[4];
	int length = 0;
	int lengthRecord[100];
	int *num[100];
	int cnt = 0;
	while(scanf("%d",&length)!=EOF)
	{
            lengthRecord[cnt] = length;
			num[cnt] = (int *)malloc(length*sizeof(int));
			memset(num[cnt],'\0',length*sizeof(int));
			scanfGet(num[cnt],lengthRecord[cnt]);
			cnt++;
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
