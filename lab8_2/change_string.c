#include "change_string.h"
#include <stdio.h>


int replace_string(const char * dest, const char * src, char ** str) {
    char * buff;
    size_t end;
    size_t begin;
    find_surname(*str, &end, &begin);
    if (my_strcmp(dest, src) == 0)
        return 1;
    while (begin != end && (buff = my_strstr(*str + begin + 1, src)) && (buff <= *str + end)) {
        if (my_strlen(dest) > my_strlen(src)) {
            char * buff2 = *str;
            *str = (char *) malloc(sizeof(char) * (my_strlen(dest) - my_strlen(src) + my_strlen(buff2)));
            if (!(*str)) {
                *str = buff2;
                return 0;
            }
            my_strcat(*str, buff2);
            free(buff2);
        }
        buff = my_strstr(*str + begin + 1, src);
        if (my_strlen(dest) > my_strlen(src)) {
            for (size_t i = 0; i < (my_strlen(dest) - my_strlen(src)); i++) {
                increase_string(buff);
            }
        } else {
            for (size_t i = 0; i < (my_strlen(src) - my_strlen(dest)); i++) {
                decrease_string(buff);
            }
        }
        for (size_t i = 0; i < my_strlen(dest); i++) {
            buff[i] = dest[i];
        }
        find_surname(*str, &end, &begin);
    }
    return 1;
}

void decrease_string(char * str) {
    size_t len = my_strlen(str);
    if (len >= 2) {
        for (size_t i = 0; i < len - 1; i++) {
            str[i] = str[i + 1];
        }
        str[len - 1] = '\0';
    }
}

void increase_string(char * str) {
    size_t len = my_strlen(str);
    if (len >= 2) {
        for (size_t i = len; i > 0; i--) {
            str[i] = str[i - 1];
        }
        str[len + 1] = '\0';
    }
}



void find_surname(char * str, size_t * end, size_t * begin) {
    *begin = find_word(str);
    *end = strlen_with_punctuation((str + *begin) + *begin);
}
