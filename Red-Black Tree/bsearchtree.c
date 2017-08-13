#include "bsearchtree.h"


_BTreeNode* makeNode(KeyType key, DataType data, size_t size){
    _BTreeNode* node = (_BTreeNode*)malloc(sizeof(_BTreeNode));
    node->key = key;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->dataSize = size;
    return node;
}
BTREE makeTree(){
    return makeNode(0, NULL, 0);
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
