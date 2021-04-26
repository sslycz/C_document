/*
 * sort.c
 *
 *  Created on: 2021��2��22��
 *      Author: hyq
 **     ������Դ: https://www.cnblogs.com/itsharehome/p/11058010.html
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
		//�ڳ�λ�ò��ȥ��Ҫ���λ����k+1
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
		 //һ�������Ƿ���λ�ý���
		 if(flag)
			 break;
	 }
 }
