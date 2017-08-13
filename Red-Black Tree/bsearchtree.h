#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef int KeyType;
typedef int* DataType;
typedef int BOOL;

typedef struct treenode{
    KeyType key;
    DataType data;
    struct treenode* left;
    struct treenode* right;
    size_t dataSize;
}_BTreeNode;

typedef _BTreeNode* BTREE;

_BTreeNode* makeNode(KeyType key, DataType data, size_t size);

BTREE makeTree();
BOOL BTREE_insert(BTREE tree, DataType target, size_t size);
DataType BTREE_deleteKey(BTREE tree, KeyType target);
DataType BTREE_deleteData(BTREE tree, DataType target);
DataType BTREE_search(BTREE tree, KeyType key);
DataType BTREE_getMin(BTREE tree);
DataType BTREE_getMax(BTREE tree);

DataType _getLeft(_BTreeNode node);
DataType _getRight(_BTreeNode node);

