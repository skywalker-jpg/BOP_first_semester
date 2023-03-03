#include "string_func.h"
char *my_strcpy(char *dest, const char *src) {
    size_t i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return dest;
}

int my_strcmp(const char *str, const char *str1) {
    char *s = (char *)str;
    char *s1 = (char *)str1;
    for (; *s && *s == *s1; s++, s1++) {}
    return (*s-*s1);
}

size_t my_strlen(const char *str) {
    size_t len = 0;
    while (*str++ != '\0') {
        len++;
    }
    return len;
}

char *my_strchr(const char *str, int c) {
    char *j = 0;

    while (*str != '\0') {
        if (*str == c) {
            j = (char *)str;
            break;
        }
        str++;
    }
    if (*str == '\0' && *str == c) {
        j = (char *)str;
    }
    return j;
}

char *my_strcat(char *dest, const char *src) {
    char *d = dest;
    while (*dest) {
        dest++;
    }
    while ((*dest++ = *src++) != '\0') {}
    return d;
}

char *my_strpbrk(const char *str1, const char *str2) {
    char *ptr = NULL;
    for (size_t i = 0; (str1[i] != '\0'); i++) {
        for (size_t j=0; (str2[j] != '\0'); j++) {
            if (str1[i] == str2[j]) {
                ptr = (char *)&str1[i];
                break;
            }
        }
        if (ptr != NULL) {
            break;
        }
    }
    return ptr;
}

int count_words(const char *str, const char * spaces) {
    int count = 0;
    char *p = (char *)str;
    for (char * pSpace; (pSpace = my_strpbrk(p, spaces)); p++) {
        if (p != pSpace) {
            count++;
            p = pSpace;
        }
    }
    if (my_strlen(p))
        count++;
    return count;
}

char *strncat(char *dest, const char *src, size_t n) {
    char *d = (char*)dest;
    char *s = (char*)src;
    for (; *d; d++) {}
    for (size_t i = 0; *s && i < n; i++, s++, d++) {
        *d = *s;
    }
    return dest;
}

size_t find_word(char * str) {
    size_t i = 0;
    while (my_strchr(" ", *str)) {
        str++;
        i++;
    }
    return i;
}

char *make_word(char * str) {
    size_t i = 0;
    char * start_word = str;
    while (!my_strchr(" \0", *str)) {
        str++;
        i++;
    }
    char * result = (char *)malloc(i * sizeof(char));
    strncat(result, start_word, i);
    result[i] = '\0';
    return result;
}

size_t strlen_with_punctuation(char * str) {
    size_t i = 0;
    while (!my_strchr(" \0", *str)) {
        str++;
        i++;
    }
    return i;
}

char *my_strstr(const char *haystack, const char *needle) {
    char *j = 0;
    int i = my_strlen(needle);
    if (i == 0) {
        j = (char *)haystack;
    }
    while (*haystack != '\0') {
        char *tmp_1 = (char*)haystack;
        char *tmp_2 = (char*)needle;

        while (*tmp_1 == *tmp_2 && i > 0) {
            tmp_1++;
            tmp_2++;
            if (*tmp_2 == '\0') {
                j = (char*)haystack;
                break;
            }
        }
        if (j != 0) {
            break;
        }
        if (i == 0) {
            j = (char*)haystack;
            break;
        }
        haystack++;
    }
    return j;
}
