/*
 * sort.c
 *
 *  Created on: 2021年2月22日
 *      Author: hyq
 **     代码来源: https://www.cnblogs.com/itsharehome/p/11058010.html
 */


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

void insertSort(int num[], int length)
{
	for(int i = 0; i < length; i++)
	{
		int temp = num[i];
		int k = i - 1;
		while(k >= 0 && num[k] > temp)
			k--;
		//腾出位置插进去，要插的位置是k+1
		for(int j = i ; j > k + 1; j--)
			num[j] = num[j-1];
		num[k+1] = temp;
	}
}

 void bubbleSort(int arr[], int length)
 {

	 for (int i = 0; i < length; i++) {
		 int flag = 1;
		 for (int j = 0; j < length -i - 1; j++) {
			 if (arr[j + 1] < arr[j]) {
				 flag = 0;
				 int t = arr[j];
				 arr[j] = arr[j+1];
				 arr[j+1] = t;
			 }
		 }
		 //一趟下来是否发生位置交换
		 if(flag)
			 break;
	 }
 }
