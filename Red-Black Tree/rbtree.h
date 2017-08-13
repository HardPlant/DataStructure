#ifndef RBTREE_H
#define RBTREE_H

typedef char BOOL;
typedef int TYPE;
/*
*Red-Black Tree
*노드에 color={red,black} 정보를 가지고 있는 트리
*red 노드의 자손은 모두 black
*루트에서 모든 리프까지의 black height가 동일
*/
BOOL Btree_insert(BTREE* tree, TYPE target);
TYPE Btree_delete(BTREE* tree, TYPE target);



#endif