
#define _assert(message, test) do { if (!(test)) return message; } while (0)
#define _run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)

#include <stdio.h>
#include "hash.h"

int tests_run = 0;
static char * hash01()
{
	HashTable_init(HashTable);
	hash_lp_add((HashElement){ "´×°Õ" }, HashTable);
	hash_lp_add((HashElement){ "ÃòÃòÃò" }, HashTable);
	hash_lp_search((HashElement) { "ÃòÃòÃò" }, HashTable);
	return 0;
}
static char * all_tests() {
	_run_test(hash01);
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