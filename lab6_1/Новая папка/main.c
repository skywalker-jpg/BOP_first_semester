#include "main_header.h"

int main() {
    char *text = NULL;
    text = input_text_data();
    printf("%s",text);
    words* array;
    if (text != NULL) {
        array=function_create_array(text);
        for (words *iter = array; iter != NULL; iter = iter->next) {
            printf("\n%s %d", iter->word, iter->repeat_count);
        }
        delete_words(array);
    }
    else{
        error_out(WRONG_TEXT_PARAMETR);
    }
}