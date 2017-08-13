#include <stdio.h>
#include <stdlib.h>
#include "testframework.h"
#include "bsearchtree.h"


int compileTest(){
    _assert(TRUE);
    return 0;
}

int makeNodeTest(){
    int data[2] = {1,0};
    _BTreeNode* Node = makeNode(0, data, sizeof(data));
    _assert(Node);
    _assert(Node->data);
    int* testdata = (int*)Node->data;
    _assert((testdata[0] == 1));
    _assert(testdata[1] == 0);
    free(Node);
    return 0;
}
int makeTreeTest(){
    BTREE Tree = makeTree();
    _assert(Tree);
    _assert(BTREE_insert(Tree, 1));

    free(Tree);
    return 0;
}

int all_tests() {
	_verify(compileTest);
	_verify(makeNodeTest);
	return 0;
}

int main(){
    testmain();
}