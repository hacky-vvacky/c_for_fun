#ifndef _STR_H_SENTRY
#define _STR_H_SENTRY

#include <stdlib.h>
#include <stddef.h>

enum chpos_search_order {
	CHPOS_NO = 0,
	CHPOS_RO = 1
};

#define CHPOS_SEARCH_ORDER enum chpos_search_order

int str_len(const char *str);

int str_copy(const char *str, char *dst, int size);

int substr(const char *str, char *dst, int offset, int len);

int str_cmp(const char *str1, const char *str2);

int str_rev(const char *str, char *dst);

int str_chpos(const char *str, char c, CHPOS_SEARCH_ORDER srch_ord);

char str_getch(const char *str, int index);

#endif 
