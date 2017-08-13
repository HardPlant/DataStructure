#include "bsearchtree.h"


_BTreeNode* makeNode(){
    _BTreeNode* node = (_BTreeNode*)malloc(sizeof(_BTreeNode));
    node->key = -1;
    node->data = -1;
    node->left = NULL;
    node->right = NULL;
    return node;
}
BTREE makeTree(){
    return makeNode();
}
BOOL BTREE_insert(BTREE tree, DataType target){
    if(tree->left == NULL && tree->right == NULL){
        return 1;
    }
}
DataType BTREE_deleteKey(BTREE tree, KeyType target);
DataType BTREE_deleteData(BTREE tree, DataType target);
DataType BTREE_search(BTREE tree, KeyType key);
DataType BTREE_getMin(BTREE tree);
DataType BTREE_getMax(BTREE tree);
