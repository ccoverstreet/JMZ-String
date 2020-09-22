// driver.c: Test Driver for JMZ String
// Cale Overstreet
// September 22, 2020
// Unit tests for JMZ String

#include <stdio.h>

#include "../jmz_string.h"

typedef struct {
	const char *name;
	void (*func)();
} func_map;

void create_destroy();

int main() {
	func_map tests[] = {
		{"Creating and Destroying JMZ String", create_destroy}
	};

	for (int i = 0; i < sizeof(tests) / sizeof(func_map); i++) {
		printf("[Driver]: Running Test \"%s\"\n", tests[i].name);
		tests[i].func();
	}

	return 0;
}

void create_destroy() {
	printf("CASDASD\n");
	jmz_string my_string = {"Hello"};
	jmz_string my_string_2 = {"World"};

	jmz_string_concat(&my_string, &my_string_2);
	printf("%s\n", my_string.data);
}
