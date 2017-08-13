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
    _BTreeNode* Node = makeNode(&data, sizeof(data));
    _assert(Node);
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