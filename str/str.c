#include "str.h"

int str_len(const char *str)
{
	int res;

	if(str == NULL || *str == '\0') {
		res = 0;
		goto exit;
	}

	for(res = 0; *str; res++, str++);
exit:
	return res;
}

int str_copy(const char *str, char *dst, int size)
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

	if(!str || org_str_len <= 1  || !dst) {
		res = -1;
		goto exit;
	}

	if(offset >= org_str_len || len <= 0 || str[0] == '\0') {
		res = -2;
		goto exit;
	}

	if(len > (org_str_len - offset))
		len = org_str_len - offset;

	for(i = 0, str += offset; i < len; i++, str++)
		dst[i] = *str;
	
	dst[i] = '\0';
	res = 0;
exit:
	return res;
}

int str_cmp(const char *str1, const char *str2)
{
	int cnt, res;
	int len1 = str_len(str1);
	int len2 = str_len(str2);

	for(cnt = 0;; str1++, str2++, cnt++) {
		if((*str1) != (*str2)) {
			res = *str1 - *str2;
			goto exit;
		}
		
		if(cnt == len1 && cnt == len2) {
			res = 0;
			goto exit;
		} else if(cnt == len1 && cnt != len2) {
			res = -1;
			goto exit;
		} else if(cnt != len1 && cnt == len2) {
			res = 1;
			goto exit;
		}
	}
exit:
	return res;
}

int str_rev(const char *str, char *dst)
{
	int i, res;
	int len = str_len(str);

	if(!str || len <= 1 || !dst) {
		res = -1;
		goto exit;
	}

	for(i = 0, str += len - 1; i < len; i++, str--) {
		dst[i] = *str;
	}
	dst[len] = '\0';
	res = 0;
exit:
	return res;
}

int str_chpos(const char *str, char c, CHPOS_SEARCH_ORDER srch_ord)
{
	int i, res;
	
	if(!str) {
		res = -1;
		goto exit;
	}

	if (srch_ord == CHPOS_NO) {
        	for (i = 0; i < str_len(str); i++) {
            		if (str[i] == c) {
                		res = i + 1;
                		goto exit;
            		}
        	}
    	} else if (srch_ord == CHPOS_RO) {
        	for (i = str_len(str) - 1; i >= 0; i--) {
            		if (str[i] == c) {
                		res = str_len(str) - i;
                		goto exit;
            		}
        	}
    	}
exit:
	return res;
}

char str_getch(const char *str, int pos)
{
	if(pos > str_len(str) || pos <= 0) {
		return -1;
	}
	return str[pos - 1];
}
