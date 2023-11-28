#include <stdlib.h>
#include "string.h"

char *mut_str(const char *str, int size)
{
	int i;
	char *ch_arr = (char *)malloc(sizeof(char) * (size + 1));
	char *res = ch_arr;
	
	if(ch_arr) {
		for(i = 0; i < size; i++) {
			*ch_arr = *str;
			str++;
			ch_arr++;
		}
		ch_arr[size] = '\0';
	}
	
	return res;
}

int str_len(const char *str)
{
	int len = 0;

	if(!(*str) || (*str) == '\0') {
		return len;
	}

	for(; *str; str++, len++);
	return len;
}
