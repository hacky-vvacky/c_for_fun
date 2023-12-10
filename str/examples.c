#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main()
{
	int cmp_res;
	const char *str = "Hello, World!";
	const char *cmp1 = "Foo";
	const char *cmp2 = "Foobar";
	char *copied = malloc(sizeof(char) * (str_len(str) + 1));
	char *substring = malloc(sizeof(char) * (str_len("World!")));
	char *reverted = malloc(sizeof(char) * (str_len(str) + 1));

	printf("Original string is \"%s\"\n", str);

	/*
	 * String copy example
	 */
	printf("\n\t---STRING COPY---\n");

	printf("Let's copy original string and change the last sign to '?'\n");
	str_copy(str, copied, str_len(str));
	copied[str_len(copied) - 1] = '?';
	printf("Copy of original string now is \"%s\"\n", copied);

	/*
	 * Substring example
	 */
	printf("\n\t---SUBSTRING---\n");
	printf("Let's get substring \"World!\" from original string\n");
	substr(str, substring, 7, 6);
	printf("Substring now is \"%s\"\n", substring);

	/*
	 * String comparsion example
	 */
	printf("\n\t---STRING COMPARSION---\n");
	printf("Let's compare two string: \"%s\" and \"%s\"\n", cmp1, cmp2);
	cmp_res = str_cmp(cmp1, cmp2);
	if(cmp_res == 0) {
		printf("Strings are equal\n");
	} else if(cmp_res > 0) {
		printf("String \"%s\" is bigger than string \"%s\"\n", cmp1, cmp2);
	} else {
		printf("String \"%s\" is bigger than string \"%s\"\n", cmp2, cmp1);
	}

	/*
	 * String reversion example
	 */
	printf("\n\t---STRING REVERSION---\n");
	printf("Let's revert original string\n");
	str_rev(str, reverted);
	printf("Reverted string now is \"%s\"\n", reverted);

	/*
	 * String getting char position example
	 */
	printf("\n\t---STRING GETTING CHAR POSITION---\n");
	printf("Let's get position of char '!' in original string\nChar position is %d\n", str_chpos(str, '!', CHPOS_NO));

	/*
	 * String getting char by position example
	 */
	printf("\n\t---STRING GETTING CHAR BY ITS POSITION---\n");
	printf("Let's get char at position 13 in original string\nChar is '%c'\n", str_getch(str, 13));

	return 0;
}
