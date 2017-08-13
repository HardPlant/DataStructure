#include <stdio.h>
#include <stdlib.h>
#include "testframework.h"
#include "bsearchtree.h"


int compileTest(){
    _assert(TRUE);
    return 0;
}

int makeNodeTest(){
    printf("[*] makeNodeTest:");
    int data[2] = {1,0};
    _BTreeNode* Node = makeNode(0, data, sizeof(data));
    _assert(Node);
    _assert(Node->data);
    int* testdata = (int*)Node->data;
    _assert((testdata[0] == 1));
    _assert(testdata[1] == 0);

    int* mallocdata = calloc(4, sizeof(int));
    int mallocdatasize = 4*sizeof(int);
    mallocdata[0] = 1;
    mallocdata[1] = 1;
    mallocdata[2] = 1;
    mallocdata[3] = 1;
    free(Node);
    Node = makeNode(0, mallocdata, sizeof(mallocdatasize));
    _assert(Node);
    _assert(Node->data);
    testdata = (int*)Node->data;
    _assert(testdata[0] == 1);
    _assert(testdata[1] == 1);
    _assert(testdata[2] == 1);
    _assert(testdata[3] == 1);
    free(testdata);
    free(Node);
    
    return 0;
}
int makeTreeTest(){
    printf("[*] TreeTest:");
    BTREE Tree = makeTree();
    int* testdata;
    int data[1] = {1};
    int data2[1] = {0};
    int data3[1] = {2};
    _assert(Tree);
    _assert(Tree->data == NULL);
    _assert(BTREE_insert(Tree, data, sizeof(data)));
    _assert(Tree->data != NULL);
    testdata = Tree->data;
    _assert(testdata[0] == 1);
    _assert(BTREE_insert(Tree, data2, sizeof(data)));
    _assert(Tree->left != NULL);
    testdata = Tree->left->data;
    _assert(testdata[0] == 0);
    _assert(BTREE_insert(Tree, data3, sizeof(data)));
    _assert(Tree->right != NULL);
    testdata = Tree->right->data;
    _assert(testdata[0] == 2);
    free(Tree);
    return 0;
}

int all_tests() {
	_verify(compileTest);
	_verify(makeNodeTest);
	_verify(makeTreeTest);
	return 0;
}

int main(){
    testmain();
}