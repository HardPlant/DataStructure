#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if ((!test)) {FAIL(); return 1; } } while (0)
#define _verify(test) printf("[*] test %d \n", tests_run); do {int r = test(); tests_run++; if (r) return r; } while(0)
#define square(n) (n)*(n)
#define TRUE 1
#define FALSE 0

#include <stdio.h>
int all_tests();
int tests_run = 0;
/*
int USL_FirstSearch_01()
{
    _assert(TRUE)
	return 0;
}
int all_tests() {
	_verify(BST_FirstSearch_01);
	return 0;
}
*/
int testmain() {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run : %d\n", tests_run);

	return result != 0;
}
