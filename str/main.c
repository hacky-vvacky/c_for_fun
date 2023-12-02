#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main()
{
	const char *str = "hello";
	const char *sub;
	int i, len = str_len(str);
	char *mutable_str = mut_str(str, len);
	char *tmp = mutable_str;
		
	printf("Mutable string from string %s with size %d: %s\n", str, len, mutable_str);
	printf("Let's prove it's mutable. Let's fully rewrite our mutable string.\n");
	for(i = 0; i < len; i++) {
		*tmp++ = 'a';
	}
	printf("String has been mutated and now is %s.\n", mutable_str);
	sub = substr(str, 0, 4);
	printf("Substring of 'hello': %s\n", sub);

	return 0;
}
