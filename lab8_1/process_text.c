#include "main_header.h"
words *process_word(words *array, char *word){
    for (words *iter = array; iter != NULL; iter = iter->next){
        char s[max_len_word];
        strcpy(s,iter->word);
        if (strcmp(iter->word,word) == 0){
            iter->repeat_count = iter->repeat_count + 1;
            return NULL;
        }
    }
    return add_word(array,word);
}

words *process_array(words *array, char *word){
    if (array == NULL){
        array = create_words(word);
    }
    else{
        words *temp_array = process_word(array, word);
        if (temp_array != NULL){
            array = temp_array;
        }
    }
    return array;
}
char *strlwr(char *str) {
    unsigned char *p = (unsigned char *)str;
    while (*p) {
        *p = tolower((unsigned char)*p);
        p++;
    }
    return str;
}
words *function_create_array(char* text){
    char sep=' ';
    char *istr;
    int l;
    istr = strtok(text, &sep);
    words *array=NULL;
    while(istr!=NULL) {
        istr = strlwr(istr);
        l = strlen(istr);
        if (l < max_len_word) {
            char *word = memory_allocation(l);
            strcpy(word, istr);
            array = process_array(array, word);
            istr = strtok(NULL, &sep);
        }
        else{
            array = process_array(array, LONG_WORD);
            istr = strtok(NULL, &sep);
        }
    }
    return array;
}