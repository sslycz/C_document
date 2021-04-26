#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"
BSTree Tree_BST;

int lBSTreemain(void)
{
//	int num[] = {4,8,2,20,12,10,21,3,5,9,31,67,23,34,15};
	int num[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	vBSTreeCreate(num,sizeof(num)/sizeof(int));
	printf("======BSTree ������� start!======\n");
	vBSTreeInOrder(&Tree_BST);
	printf("======        Over!         ======\n");

	return 0;
}

/*************************
*��������vBSTreePreOrder
*���ܣ�ǰ����� 
***************************/
void vBSTreePreOrder(BSTree * tree)
{
	if(tree != NULL)
	{
		printf("tree->key = %d \n",tree->key);
		vBSTreePreOrder(tree->leftChild);
		vBSTreePreOrder(tree->rightChild);
	}
}

/*************************
*��������vBSTreePreOrder
*���ܣ��������
***************************/
void vBSTreeInOrder(BSTree * tree)
{
	if(tree != NULL)
	{
		vBSTreeInOrder(tree->leftChild);
		printf("tree->key = %d \n",tree->key);
		vBSTreeInOrder(tree->rightChild);
	}
}
/*************************
*��������vBSTreeRearOrder
*���ܣ��������
***************************/
void vBSTreeRearOrder(BSTree * tree)
{
	if(tree != NULL)
	{
		vBSTreeRearOrder(tree->leftChild);
		vBSTreeRearOrder(tree->rightChild);
		printf("tree->key = %d \n",tree->key);
	}
}


/*===============================BST====================================*/
/*************************
*��������
*���ܣ�����BST�ڵ�
***************************/
BSTree * pBSTreeNewNode(int key)
{
	BSTree * node = (BSTree *)malloc(sizeof(BSTree));
	node->key = key;
	node->leftChild = NULL;
	node->rightChild = NULL;
	return node;
}
/*************************
*��������vBSTreeInsert
*���ܣ�BSTree����
***************************/
void vBSTreeInsert(BSTree * tree, int key)
{
	BSTree * relay;
	int direction = 0;

	while(tree != NULL)
	{
		relay = tree;
		if(key < tree->key)
		{
			tree = tree->leftChild;
			direction = 1;
		}
		else if(key > tree->key)
		{
			tree = tree->rightChild;
			direction = 2;
		}
		else
		{
			;
		}
	}	
	if(1 == direction)
	{
		relay->leftChild = pBSTreeNewNode(key);
	}
	else if(2 == direction)
	{
		relay->rightChild = pBSTreeNewNode(key);
	}
	else
	{
		printf("error!\n");
	}
	
	
	
}
/*************************
*��������vBSTreeCreate
*���ܣ���������������
***************************/
void vBSTreeCreate(int num[], int length)
{
	int i;
	for(i = 0; i < length; i++)
	{	
		//printf("insert %d\n", treeTemp[i].key);
		vBSTreeInsert(&Tree_BST,num[i]);
	}
}
