#include "main_header.h"
typedef struct words_tag words;

words *create_words(char *str){
    words *new_words= memory_alloc_for_words();
    if (new_words != NULL){
        strcpy(new_words->word,str);
        new_words->repeat_count = 1;
        new_words->next = NULL;
    }
    return new_words;
}

words *add_word(words *words_array, char *str){
    words *new_words = create_words(str);
    if (new_words != NULL){
        new_words->next = words_array;
    }
    return new_words;
}

void delete_words(words *array){
    if (array->next != NULL){
        delete_words(array->next);
    }
    free(array);
}
