#include "bsearchtree.h"

BOOL BTREE_insert(BTREE tree, DataType target);
DataType BTREE_deleteKey(BTREE tree, KeyType target);
DataType BTREE_deleteData(BTREE tree, DataType target);
DataType BTREE_search(BTREE tree, KeyType key);
DataType BTREE_getMin(BTREE tree);
DataType BTREE_getMax(BTREE tree);


_BTreeNode* makeNode(){
    _BTreeNode* node = (_BTreeNode*)malloc(sizeof(_BTreeNode));
    return node;
}
BTREE makeTree(){
    return makeNode();
}