#include "error.h"

void error(char* msg)
{
	fprintf(stderr, msg);
	exit(1);
}