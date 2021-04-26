
#ifndef TREE_RBTREE_H_
#define TREE_RBTREE_H_

#include "typeDefine.h"

typedef struct RBTreeStruct{
	int32 key;
	struct AVLTreeStruct * leftChild;
	struct AVLTreeStruct * rightChild;
	struct AVLTreeStruct * parent;
	int8 color;
}RBTree;

int8 sTreeRBTGetColor(RBTree * node);

#endif
