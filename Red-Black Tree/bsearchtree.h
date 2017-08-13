#pragma once

typedef int KeyType;
typedef int DataType;
typedef int BOOL;

typedef struct treenode{
    KeyType key;
    DataType data;
    struct node* left;
    struct node* right;
    size_t DataSize;
}Node;

typedef Node* BTREE;


BOOL BTREE_insert(BTREE tree, DataType target);
DataType BTREE_deleteKey(BTREE tree, KeyType target);
DataType BTREE_deleteData(BTREE tree, DataType target);
DataType BTREE_search(BTREE tree, KeyType key);
DataType BTREE_getMin(BTREE tree);
DataType BTREE_getMax(BTREE tree);

DataType _getLeft(Node node);
DataType _getRight(Node node);