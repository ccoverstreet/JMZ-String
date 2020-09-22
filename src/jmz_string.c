// jmz_string.c: Jarmuz String Library
// Cale Overstreet
// September 22, 2020

#include "../jmz_string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *jmz_str_concat(const char *a, const char *b) {
	char *concat_str = calloc(strlen(a) + strlen(b) + 1, sizeof(char));
	strcat(concat_str, a);
	strcat(concat_str, b);

	return concat_str;
}
