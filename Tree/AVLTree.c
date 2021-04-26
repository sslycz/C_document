#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.h"

AVLTree * Tree_AVL;

int32 lAVLTreemain(void)
{
	int32 num[] = {4,8,2,20,12,10,21,3,5,9,31,67,23,34,15};
//	int32 num[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	
	vAVLTreeCreate(num,sizeof(num)/sizeof(int32));
	printf("======AVLTree 中序遍历 start!======\n");
	vAVLTreeInOrder(Tree_AVL);
	return 0;
}
/*************************
*函数名：vAVLTreePreOrder
*功能：前序遍历 
***************************/
void vAVLTreePreOrder(AVLTree * tree)
{
	if(tree != NULL)
	{
		printf("tree->key = %d \n",tree->key);
		vAVLTreePreOrder(tree->leftChild);
		vAVLTreePreOrder(tree->rightChild);
	}
}

/*************************
*函数名：vAVLTreePreOrder
*功能：中序遍历
***************************/
void vAVLTreeInOrder(AVLTree * tree)
{
	if(tree != NULL)
	{
		vAVLTreeInOrder(tree->leftChild);
		printf("tree->key = %d \n",tree->key);
		if(NULL != tree->leftChild)
		{
			if(tree->leftChild->parent != tree)
			{
				printf("error parent:tree = 0x%x, tree->leftChild->parent = 0x%x\n",tree,tree->leftChild->parent);
			}
		}

		if(NULL != tree->rightChild)
		{
			if(tree->rightChild->parent != tree)
			{
				printf("error parent:tree = 0x%x, tree->rightChild->parent = 0x%x\n",tree,tree->rightChild->parent);
			}
		}
		vAVLTreeInOrder(tree->rightChild);
	}
}
/*************************
*函数名：vTreeRearOrder
*功能：后序遍历
***************************/
void vAVLTreeRearOrder(AVLTree * tree)
{
	if(tree != NULL)
	{
		vAVLTreeRearOrder(tree->leftChild);
		vAVLTreeRearOrder(tree->rightChild);
		printf("tree->key = %d \n",tree->key);
	}
}



/*===============================AVL====================================*/

/*************************
*函数名：pTreeAVL_LL_Rotate
*功能：平衡二叉树LL型右旋
***************************/
AVLTree * pTreeAVL_LL_Rotate(AVLTree * tree)
{
	AVLTree * TempNode = tree->leftChild;         /*保存原父节点的左孩子到TempNode*/
	AVLTree * ParentNode = tree->parent;    

	tree->leftChild = TempNode->rightChild;       /*1、原父节点的左孩子的右子树嫁接到原父节点的左孩子（配合图理解）*/
	if(NULL != tree->leftChild)                   
	{
		tree->leftChild->parent = tree;           /*当前父节点的左孩子（移动了的节点）不为空，则要更新父节点*/
	}

	TempNode->rightChild = tree;                  /*2、*/
	if(NULL != TempNode->rightChild)
	{
		TempNode->rightChild->parent = TempNode;  /*更新父节点*/
	}

	TempNode->parent = ParentNode;                /*原父节点的父节点交给原左孩子的父节点*/

	tree->height = 1 + MAX(lTreeAVLgetHeight(tree->leftChild),lTreeAVLgetHeight(tree->rightChild));
	TempNode->height = 1 + MAX(lTreeAVLgetHeight(TempNode->leftChild),lTreeAVLgetHeight(TempNode->rightChild));
	
	return TempNode;
}

/*************************
*函数名：
*功能：平衡二叉树RR型左旋
***************************/
AVLTree * pTreeAVL_RR_Rotate(AVLTree * tree)
{
	AVLTree * TempNode = tree->rightChild;
	AVLTree * ParentNode = tree->parent;

	tree->rightChild = TempNode->leftChild;
	if(NULL != tree->rightChild)
	{
		tree->rightChild->parent = tree;
	}

	TempNode->leftChild = tree;
	if(NULL != TempNode->leftChild)
	{
		TempNode->leftChild->parent = TempNode;
	}

	TempNode->parent = ParentNode;

	tree->height = 1 + MAX(lTreeAVLgetHeight(tree->leftChild),lTreeAVLgetHeight(tree->rightChild));
	TempNode->height = 1 + MAX(lTreeAVLgetHeight(TempNode->leftChild),lTreeAVLgetHeight(TempNode->rightChild));
	
	return TempNode;
}

/*************************
*函数名：
*功能：平衡二叉树LR型
***************************/
AVLTree * pTreeAVL_LR_Rotate(AVLTree * tree)
{
	tree->leftChild = pTreeAVL_RR_Rotate(tree->leftChild);
	if(NULL != tree->leftChild)
	{
		tree->leftChild->parent = tree;
	}
	return pTreeAVL_LL_Rotate(tree);
}

/*************************
*函数名：
*功能：平衡二叉树RL型
***************************/
AVLTree * pTreeAVL_RL_Rotate(AVLTree * tree)
{
	tree->rightChild = pTreeAVL_LL_Rotate(tree->rightChild);
	if(NULL != tree->rightChild)
	{
		tree->rightChild->parent = tree;
	}
	return pTreeAVL_RR_Rotate(tree);
}


/*************************
*函数名：
*功能：平衡二叉树获取节点高度
***************************/
int32 lTreeAVLgetHeight(AVLTree * node)
{
	int32 height = 0;
	if(NULL != node)
	{
		height = node->height;
	}
	else
	{
		; /*do nothing*/
	}
	return height;
}

/*************************
*函数名：
*功能：平衡二叉树获取平衡因子
***************************/
int32 lTreeAVLgetBF(AVLTree * node)
{
	int32 BF = 0;
	if(NULL != node)
	{
		
		BF = lTreeAVLgetHeight(node->leftChild) - lTreeAVLgetHeight(node->rightChild);
	}
	else
	{
		; /*do nothing*/
	}
	
	return BF;
}

/*************************
*函数名：
*功能：创建AVL节点
***************************/
AVLTree * pTreeAVLNewNode(int32 key)
{
	AVLTree * node = (AVLTree *)malloc(sizeof(AVLTree));
	node->key = key;
	node->height = 1;
	node->leftChild = NULL;
	node->rightChild = NULL;
	node->parent = NULL;
	return node;
}

/*************************
*函数名：
*功能：平衡二叉树插入
***************************/
AVLTree * pTreeAVLInsert(AVLTree * node, int32 key)
{
	int32 balance ;
	if(NULL == node)
	{
		return pTreeAVLNewNode(key);
	}
	else
	{
		
		if(key < node->key)
		{
			node->leftChild = pTreeAVLInsert(node->leftChild, key);
			node->leftChild->parent = node;
		}
		else if(key > node->key)
		{
			node->rightChild = pTreeAVLInsert(node->rightChild, key);
			node->rightChild->parent = node;
		}
		else
		{
			return node;
		}


		node->height = 1 + MAX(lTreeAVLgetHeight(node->leftChild),lTreeAVLgetHeight(node->rightChild));

		balance = lTreeAVLgetBF(node);

		if((balance > 1) && (key < node->leftChild->key)) /* LL型 */
		{
			node = pTreeAVL_LL_Rotate(node);
		}
		else if((balance > 1) && (key > node->leftChild->key)) /*LR型*/
		{
			node = pTreeAVL_LR_Rotate(node);
		}
		
		else if((balance < -1) && (key > node->rightChild->key)) /*RR型*/
		{
			node = pTreeAVL_RR_Rotate(node);
		}
		else if((balance < -1) && (key < node->rightChild->key)) /*RL型*/
		{
			node = pTreeAVL_RL_Rotate(node);
		}
		else
		{
			;
		}
		
		return node;
	}
}

/*************************
*函数名：
*功能：创建平衡二叉树
***************************/
void vAVLTreeCreate(int32 num[], int32 length)
{
	int32 i;
	for(i = 0; i < length; i++)
	{
		printf("insert: %d\n",num[i]);
		Tree_AVL = pTreeAVLInsert(Tree_AVL,num[i]);
	}

}


/*************************
*函数名：MAX
*功能：取最大值
***************************/

int32 MAX(int32 a, int32 b)
{
	return a > b ? a : b;
}

