
#ifndef TREE_BSTREE_H_
#define TREE_BSTREE_H_

#include "../TypeDefine/typeDefine.h"


typedef struct BSTreeStruct{
	int32 key;
	struct BSTreeStruct * leftChild;
	struct BSTreeStruct * rightChild;
	struct BSTreeStruct * parent;
}BSTree;

void vBSTreePreOrder(BSTree * tree);
void vBSTreeInOrder(BSTree * tree);
void vBSTreeRearOrder(BSTree * tree);

/** BSTree **/

void vBSTreeInsert(BSTree * tree, int32 key);
void vBSTreeCreate(int32 num[], int32 length);

#endif
