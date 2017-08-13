#include <stdio.h>
#include "testframework.h"
#include "bsearchtree.h"


int compileTest(){
    _assert(TRUE);
    return 0;
}

int makeNodeTest(){
    _BTreeNode* Node = makeNode();
    _assert(TRUE);
    return 0;
}
int makeTreeTest(){
    _assert(TRUE);
    return 0;
}

int all_tests() {
	_verify(compileTest);
	return 0;
}

int main(){
    testmain();
}