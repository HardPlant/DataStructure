#include <stdio.h>
#include "node.h"
int main()
{
	testmain();
	int k, n;
	Queue* kbonacci;

	printf("���� k�� �Է��ϼ��� : ");
	scanf("%d", &k);
	printf("k-order �Ǻ���ġ �������� �� ��° ���� ǥ���մϱ�?");
	scanf("%d", &n);
	kbonacci = makeQueue();
	makeKbonacci(kbonacci, k, n);
	printf("������ F_%d ���� %d�Դϴ�.\n",n, at(kbonacci, n-1));

	return 0;
}