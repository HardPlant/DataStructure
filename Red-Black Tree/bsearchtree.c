#include "bsearchtree.h"
#define TRUE 1
#define FALSE 0

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
        BOOL (*cmp)(_BTreeNode*,_BTreeNode*), int check)
{
    if(cmp(*dst, *src) ^ ~(check)){
        node_swap(dst, src);
        printf("swapped\n");
        return 1;
    }
    else{
        return 0;
    }
}

BOOL BTREE_insert(BTREE tree, DataType target, size_t size){
    //NULL Check
    if(tree == NULL || target == NULL) {
        printf("Null\n");
        return 0;
    }

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
        printf("func passed\n");
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
        else tree->left = node;
        checkAndExchange(&(tree->left),&(tree->right),node_isLE, FALSE);
        return 1;
    }
    printf("Undefined\n");
    return 0;
}
DataType BTREE_deleteKey(BTREE tree, KeyType target){
    
}
DataType BTREE_deleteData(BTREE tree, DataType target);
DataType BTREE_search(BTREE tree, KeyType key);
DataType BTREE_getMin(BTREE tree);
DataType BTREE_getMax(BTREE tree);

BOOL BTREE_fprintf(BTREE tree, int fd){
    if(tree == NULL && tree->data==NULL ) return 1;
    BTREE_fprintf(tree->left, fd);
    fprintf(fd, "%d\n", tree->data);
    BTREE_fprintf(tree->right,fd);
}
BOOL BTREE_sprintf(BTREE tree, char* fd){
    if(tree == NULL) return 1;
    BTREE_sprintf(tree->left, fd);
    sprintf(fd, "%d ", tree->data);
    BTREE_sprintf(tree->right,fd);
}

BOOL BTREE_destroy(BTREE tree){
    if(tree == NULL) return 1;
    BTREE_destroy(tree->left);
    BTREE_destroy(tree->right);
    free(tree);
}