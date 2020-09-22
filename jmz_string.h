// jmz_string.h: Jarmuz String Library header file
// Cale Overstreet
// September 22, 2020
// C Library for better string handling and utility functions

typedef struct {
	char *data;
} jmz_string;

jmz_string concat(jmz_string *a, jmz_string *b);

