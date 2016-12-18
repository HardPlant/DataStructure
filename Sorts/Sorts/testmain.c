#include <stdio.h>
#include "SimpleSort.h"
#include "ComplexSort.h"
#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)

int tests_run = 0;

int foo = 7;
int bar = 4;

int isSorted(int list[], int length)
{
	int index;
	for (index = 0; index < length-2; index++)
		if (list[index] < list[index + 1]) return 1;
	printf("현재 배열 : ");
	for (int i = 0; i < length; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}

static char * simpleSortTest()
{
	int list[] = { 1,3,2,4,6,1,9 };
	int listLength = sizeof(list) / sizeof(int);
	selectSort(list, listLength);
	mu_assert("정렬된 값이 올바르지 않음", isSorted(list,listLength));
	return 0;
}
static char * insertSortTest()
{
	int list[] = { 10,40,30,5,22,6,15,9,60 };
	int listLength = sizeof(list) / sizeof(int);
	insertSort(list, listLength);
	mu_assert("정렬된 값이 올바르지 않음", isSorted(list, listLength));
	return 0;
}
static char * quickSortTest()
{
	int list[] = { 10,40,30,5,22,6,15,9,60 };
	int listLength = sizeof(list) / sizeof(int);
	quickSort(list, listLength);
	mu_assert("정렬된 값이 올바르지 않음", isSorted(list, listLength));
	return 0;
}
static char * heapSortTest()
{
	int list[] = { 10,40,30,5,22,6,15,9,60 };
	int listLength = sizeof(list) / sizeof(int);
	heapSort(list, listLength);
	printf("After: \n");
	for (int i = 0; i < 9; i++)
		printf("%d ", list[i]);
	printf("\n");
	mu_assert("정렬된 값이 올바르지 않음", isSorted(list, listLength));
	return 0;
}

static char * all_tests() {/*
	mu_run_test(simpleSortTest);
	mu_run_test(insertSortTest);
	mu_run_test(quickSortTest);*/
	mu_run_test(heapSortTest);
	return 0;
}

int main(int argc, char **argv) {
	char *result = all_tests();
	if (result != 0) {
		printf("%s\n", result);
	}
	else {
		printf("ALL TESTS PASSED\n");
	}
	printf("Tests run: %d\n", tests_run);

	return result != 0;
}