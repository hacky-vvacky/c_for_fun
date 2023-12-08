#include <stdlib.h>
#include "string.h"

int str_len(const char *str)
{
	int len = 0;
	const char *p = str;

	if(p == NULL || p[0] == '\0')
		return len;

	for(len = 0; *p; len++, p++);

	return len;
}

int mut_str(const char *str, char *dst, int size)
{
	int res, i;
	
	if(!str || !dst) {
		res = -1;
		goto exit;
	}

	for(i = 0; i < size; i++, str++)
		dst[i] = *str;

	dst[size] = '\0';
	res = 0;
exit:
	return res;
}

int substr(const char *str, char *dst, int offset, int len)
{	
	int res, i;
	int org_str_len = str_len(str);
	const char *p = str;

	if(!str || !dst) {
		res = -1;
		goto exit;
	}

	if(offset >= org_str_len || len <= 0 || str[0] == '\0') {
		res = -2;
		goto exit;
	}

	if(len > (org_str_len - offset))
		len = org_str_len - offset;

	for(i = 0, p += offset; i < len; i++, p++)
		dst[i] = *p;
	
	dst[i] = '\0';
	res = 0;
exit:
	return res;
}

int str_cmp(const char *str1, const char *str2)
{
	int res = 0;
	int equal = 1;
	const char *p1 = str1;
	const char *p2 = str2;

	while(equal) {
		if((*p1) == (*p2)) {
			p1++;
			p2++;
			continue;
		} else {
			res = *p1 - *p2;
			equal = 0;
		}
	}

	return res;
}
