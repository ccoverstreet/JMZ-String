// driver.c: Test Driver for JMZ String
// Cale Overstreet
// September 22, 2020
// Unit tests for JMZ String

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../jmz_string.h"

typedef struct {
	const char *name;
	int (*func)();
} func_map;

int concat_test();

int main() {
	func_map tests[] = {
		{"String Concatentation", concat_test}
	};

	for (int i = 0; i < sizeof(tests) / sizeof(func_map); i++) {
		printf("[Driver]: Running Test \"%s\"\n", tests[i].name);
		if (tests[i].func()) {
			printf("[Driver]: ERROR Test Failed\n");
		}
	}

	return 0;
}

int concat_test() {
	const char *str_1 = "Hello";
	const char *str_2 = " World!";

	char *concat_str = jmz_str_concat(str_1, str_2);

	printf("\"%s\" + \"%s\" = \"%s\"\n", str_1, str_2, concat_str);

	if (!strcmp("Hello World!", concat_str)) {
		printf("Concatenated string does not match inputs\n");
		return 1;
	}

	free(concat_str);

	return 0;
}
