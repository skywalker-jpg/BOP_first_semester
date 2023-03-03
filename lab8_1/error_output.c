
#include "main_header.h"
void error_out(int KEY){
    if(KEY==WRONG_TEXT_PARAMETR){
        printf(WRONG_TEXT_PARAMETR_OUTPUT);
    }
    if(KEY==WRONG_WORD){
        printf(WRONG_WORD_OUTPUT);
    }
}