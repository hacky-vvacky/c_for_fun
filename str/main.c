#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main()
{
	int cmp_res;
	const char *str = "Hello, World!";
	const char *cmp1 = "Nikita Bulavin";
	const char *cmp2 = "Nikita Belyaev";
	char *mutable = malloc(sizeof(mutable) * (str_len(str) + 1));
	char *substring = malloc(sizeof(substring) * (str_len(str) + 1));

	printf("Original string is \"%s\"\n", str);

	/*
	 * String mutation example
	 */
	printf("\tSTRING MUTATION\n");

	printf("Let's create mutable copy of original string and change the last sign to '?'\n");
	mut_str(str, mutable, str_len(str));
	mutable[str_len(mutable) - 1] = '?';
	printf("Mutated string now is \"%s\"\n", mutable);

	/*
	 * Substring example
	 */
	printf("\tSUBSTRING\n");
	printf("Let's get substring \"World!\" from original string\n");
	substr(str, substring, 7, 6);
	printf("Substring now is \"%s\"\n", substring);

	/*
	 * String comparsion example
	 */
	printf("\tSTRING COMPARSION\n");
	printf("Let's compare two string: \"%s\" and \"%s\"\n", cmp1, cmp2);
	cmp_res = str_cmp(cmp1, cmp2);
	if(cmp_res == 0) {
		printf("Strings are equal\n");
	} else if(cmp_res > 0) {
		printf("String \"%s\" bigger than string \"%s\"\n", cmp1, cmp2);
	} else {
		printf("String \"%s\" bigger than string \"%s\"\n", cmp2, cmp1);
	}

	return 0;
}
