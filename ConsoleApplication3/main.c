#include <stdio.h>
#include "node.h"
int main()
{
	int k, n;
	Queue* kbonacci;

	printf("차수 k를 입력하세요 : ");
	scanf("%d", &k);
	printf("k-order 피보나치 수열에서 몇 번째 값을 표시합니까?");
	scanf("%d", &n);
	kbonacci = makeQueue();
	makeKbonacci(kbonacci, k, n);
	printf("수열의 F_%d 값은 %d입니다.\n",n, at(kbonacci, n-1));
	destroy(kbonacci);
	return 0;
}