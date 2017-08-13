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

void node_swap(_BTreeNode** dst, _BTreeNode** src){
    _BTreeNode* tmp = *dst;
    *dst = *src;
    *src = tmp;
}
BOOL node_isLE(_BTreeNode* dst, _BTreeNode* src){
    if(dst->data[0] <= src-> data[0]) return 1;
    else return 0;
}
BOOL checkAndExchange(_BTreeNode** dst, _BTreeNode** src,
        BOOL (*cmp)(_BTreeNode*,_BTreeNode*))
{
    if(cmp(*dst, *src)){
        node_swap(dst, src);
        return 1;
    }
    else{
        return 0;
    }
}

BOOL BTREE_insert(BTREE tree, DataType target, size_t size){
    //NULL Check
    if(tree == NULL || target == NULL) return 0;
    //
    if(tree->data == NULL){
        tree->data = target;
        return 1;
    }
    if(tree->left == NULL && tree->right == NULL){
        _BTreeNode* node = makeNode(target[0], target, size);
        if(tree->data[0] > node->data[0]){
            tree->left = node;
            return 1;
        }
        if(tree->data[0] <= node->data[0]){
            tree->right = node;
            return 1;
        }
    }
    if(tree->left != NULL && tree->right != NULL){
        if(tree->data[0] > target[0]){
            return BTREE_insert(tree->left, target, size);
        }
        if(tree->data[0] <= target[0]){
            return BTREE_insert(tree->right, target, size);
        }
    }
    else{// tree->left || tree->right
        _BTreeNode* node = makeNode(target[0], target, size);
        if(tree->left != NULL) tree->right = node;
        if(tree->right != NULL) tree->left = node;
        checkAndExchange(&(tree->left),&(tree->right),node_isLE);
        return 1;
    }
    return 0;
}
DataType BTREE_deleteKey(BTREE tree, KeyType target);
DataType BTREE_deleteData(BTREE tree, DataType target);
DataType BTREE_search(BTREE tree, KeyType key);
DataType BTREE_getMin(BTREE tree);
DataType BTREE_getMax(BTREE tree);
