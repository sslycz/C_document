/*
 * test.c
 *
 *  Created on: 2021年2月22日
 *      Author: hyq
 */

#include <stdio.h>
#include <stdlib.h>
#include <test_tree.h>
#include "AVLTree.h"
#include "BSTree.h"
#include "RBTree.h"

BSTree Tree_BST;
AVLTree * Tree_AVL;

void treeTest(void)
{
//	int num[] = {4,8,2,20,12,10,21,3,5,9,31,67,23,34,15};
	int num[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	vBSTreeCreate(num,sizeof(num)/sizeof(int));
	printf("======BSTree 中序遍历 start!======\n");
	vBSTreeInOrder(&Tree_BST);
	printf("======        Over!         ======\n");

	vAVLTreeCreate(num,sizeof(num)/sizeof(int));
	printf("======AVLTree 中序遍历 start!======\n");
	vAVLTreeInOrder(Tree_AVL);
	printf("======        Over!         ======\n");
}
