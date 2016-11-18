#include <stdio.h>
#include "tree.h"
int main()
{
	TreeNode n7 = { 1,NULL,NULL };
	TreeNode n6 = { 2,NULL,NULL };
	TreeNode n5 = { 3,NULL,NULL };
	TreeNode n4 = { 4,NULL,NULL };
	TreeNode n3 = { 5,&n6,NULL };
	TreeNode n2 = { 6,&n4,&n5 };
	TreeNode n1 = { 7,&n2,&n3 };
	findMinMax(&n1);
	return 0;
}