#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"
BSTree Tree_BST;

int lBSTreemain(void)
{
//	int num[] = {4,8,2,20,12,10,21,3,5,9,31,67,23,34,15};
	int num[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	vBSTreeCreate(num,sizeof(num)/sizeof(int));
	printf("======BSTree 中序遍历 start!======\n");
	vBSTreeInOrder(&Tree_BST);
	printf("======        Over!         ======\n");

	return 0;
}

/*************************
*函数名：vBSTreePreOrder
*功能：前序遍历 
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
*函数名：vBSTreePreOrder
*功能：中序遍历
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
*函数名：vBSTreeRearOrder
*功能：后序遍历
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
*函数名：
*功能：创建BST节点
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
*函数名：vBSTreeInsert
*功能：BSTree插入
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
*函数名：vBSTreeCreate
*功能：创建二叉排序树
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
