#ifndef TREE_AVLTREE_H_
#define TREE_AVLTREE_H_


#include "typeDefine.h"

typedef struct AVLTreeStruct{
	int32 key;
	struct AVLTreeStruct * leftChild;
	struct AVLTreeStruct * rightChild;
	struct AVLTreeStruct * parent;
	int32 height;
	int32 BF; /**balance factor∆Ω∫‚“Ú◊”**/
}AVLTree;


void vAVLTreePreOrder(AVLTree * tree);
void vAVLTreeInOrder(AVLTree * tree);
void vAVLTreeRearOrder(AVLTree * tree);

/** AVL Tree **/

AVLTree * pTreeAVL_LL_Rotate(AVLTree * tree);
AVLTree * pTreeAVL_RR_Rotate(AVLTree * tree);
AVLTree * pTreeAVL_LR_Rotate(AVLTree * tree);
AVLTree * pTreeAVL_RL_Rotate(AVLTree * tree);

int32 lTreeAVLgetHeight(AVLTree * node);
int32 lTreeAVLgetBF(AVLTree * node);
AVLTree * pTreeAVLNewNode(int32 key);
AVLTree * pTreeAVLInsert(AVLTree * node, int32 key);
void vAVLTreeCreate(int32 num[], int32 length);
int32 MAX(int32 a, int32 b);

#endif
