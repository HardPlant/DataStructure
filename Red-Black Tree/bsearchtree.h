#pragma once

typedef KeyType int
typedef DataType int
typedef BOOL int

typedef treenode{
    KeyType key;
    DataType data;
    struct node* left;
    struct node* right;
    size_t DataSize;
}Node;

typedef BTREE Node*;


BOOL BTREE_insert(BTREE tree, DataType target);
DataType BTREE_deleteKey(BTREE tree, KeyType target);
DataType BTREE_deleteData(BTREE tree, DataType target);
DataType BTREE_search(BTREE tree, KeyType key);
DataType BTREE_getMin(BTREE tree);
DataType BTREE_getMax(BTREE tree);

DataType _getLeft(Node node);
DataType _getRight(Node node);