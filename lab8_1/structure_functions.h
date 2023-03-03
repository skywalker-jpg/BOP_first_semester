#ifndef LABBB_STRUCTURE_FUNCTIONS_H
#define LABBB_STRUCTURE_FUNCTIONS_H
#include "main_header.h"
#include "define.h"
typedef struct words_tag{
    char word[max_len_word];
    int repeat_count;
    struct words_tag *next;
}words;

words *add_word(words *words_array, char *str);
words *create_words(char *str);
void delete_words(words *array);

#endif //LABBB_STRUCTURE_FUNCTIONS_H
