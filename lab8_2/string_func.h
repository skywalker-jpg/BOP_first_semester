#ifndef INC_8_2_STRING_FUNC_H
#define INC_8_2_STRING_FUNC_H
#include <stdio.h>
#include <stdlib.h>

#define ERROR_INPUT_COUNT_STRINGS 1
#define ERROR_INPUT_STRINGS 2
#define ERROR_INPUT_REPLACE_STRING 3

char *my_strcpy(char *dest, const char *src);
int my_strcmp(const char *str, const char *str1);
size_t my_strlen(const char *str);
char *my_strchr(const char *str, int c);
char *my_strcat(char *dest, const char *src);
char *my_strpbrk(const char *str1, const char *str2);
int count_words(const char *str, const char * spaces);
char *strncat(char *dest, const char *src, size_t n);
size_t find_word(char * str);
char *make_word(char * str);
size_t strlen_with_punctuation(char * str);
char *my_strstr(const char *haystack, const char *needle);

#endif
