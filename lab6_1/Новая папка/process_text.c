#include "main_header.h"
words *process_word(words *array, char *word){
    for (words *iter = array; iter != NULL; iter = iter->next){
        char s[100];
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
words *function_create_array(char* text){
    char sep=' ';
    char *istr;
    int l;
    istr = strtok(text, &sep);
    words *array=NULL;
    while(istr!=NULL) {
        l = strlen(istr);
        if (l < 100) {
            char *word = memory_allocation(l);
            strcpy(word, istr);
            array = process_array(array, word);
            istr = strtok(NULL, &sep);
        }
        else{
            error_out(WRONG_WORD);
            break;
        }
    }
    return array;
}