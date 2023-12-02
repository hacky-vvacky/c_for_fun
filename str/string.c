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

const char *substr(const char *str, int offset, int len)
{	
	int i;
	int strlen = str_len(str);
	const char *p = str;
	char *res = (char *) malloc(sizeof(char) * (len + 1));

	if(str == NULL || !res) {
		return NULL;
	}

	if(offset >= strlen || len <= 0 || str[0] == '\0') {
		char *empty = (char *) malloc(sizeof(char));
		empty[0] = '\0';
		return empty;
	}

	if(len > (strlen - offset)) {
		len = strlen - offset;
	}

	for(i = 0, p += offset; i < len; i++, p++) {
		res[i] = *p;
	}
	res[i] = '\0';

	return res;
}
