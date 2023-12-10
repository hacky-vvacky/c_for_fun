extern const int CHPOS_NO;
extern const int CHPOS_RO;

int str_len(const char *str);

int str_copy(const char *str, char *dst, int size);

int substr(const char *str, char *dst, int offset, int len);

int str_cmp(const char *str1, const char *str2);

int str_rev(const char *str, char *dst);

int str_chpos(const char *str, char c, int search_order);

char str_getch(const char *str, unsigned int index);
