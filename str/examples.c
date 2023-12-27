#include <stdio.h>
#include <stdlib.h>
#include "str.h"

const char *orig = "Hello, World!";

void string_copy_example()
{
	char *copy = malloc(sizeof(char) * (str_len(orig) + 1));
	
	printf("\n---STRING COPY---\n");

	printf("Let's copy original string and change the last sign to '?'\n");
	str_copy(orig, copy, str_len(orig));
	copy[str_len(copy) - 1] = '?';
	printf("Copy of original string now is \"%s\"\n", copy);
}

void substring_example()
{
	char *substring = malloc(sizeof(char) * (str_len("World!")));
	
	printf("\n---SUBSTRING---\n");
	
	printf("Let's get substring from original string starting from position 7 of length 6\n");
	substr(orig, substring, 7, 6);
	printf("Substring now is \"%s\"\n", substring);
}

void string_comparsion_example()
{
	int cmp_res;
	const char *cmp1 = "Foo";
	const char *cmp2 = "Foobar";

	printf("\n---STRING COMPARSION---\n");
	
	printf("Let's compare two string: \"%s\" and \"%s\"\n", cmp1, cmp2);
	cmp_res = str_cmp(cmp1, cmp2);
	if(cmp_res == 0) {
		printf("Strings are equal\n");
	} else if(cmp_res > 0) {
		printf("String \"%s\" is bigger than string \"%s\"\n", cmp1, cmp2);
	} else {
		printf("String \"%s\" is bigger than string \"%s\"\n", cmp2, cmp1);
	}
}

void string_reversion_example()
{
	char *reverted = malloc(sizeof(char) * (str_len(orig) + 1));
	
	printf("\n---STRING REVERSION---\n");
	printf("Let's revert original string\n");
	str_rev(orig, reverted);
	printf("Reverted string now is \"%s\"\n", reverted);
}

void get_char_position_example()
{
	int pos;

	printf("\n---STRING GETTING CHAR POSITION---\n");
	
	printf("Let's get position of char '!' in original string");
	pos = str_chpos(orig, '!', CHPOS_NO);
	printf("Char position is %d\n", pos);
}

void get_char_by_position_example()
{
	char ch;

	printf("\n---STRING GETTING CHAR BY ITS POSITION---\n");
	
	printf("Let's get char at position 13 in original string\n");
	ch = str_getch(orig, 13);
	printf("Char is '%c'\n", ch);
}

int main()
{
	string_copy_example();
	substring_example();
	string_comparsion_example();
	string_reversion_example();
	get_char_position_example();
	get_char_by_position_example();

	return 0;
}
