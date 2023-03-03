#include "errors.h"

void errors_func(int problem_code){
    switch(problem_code){
        case FORMAT_OUTPUT_STRING_MEMORY_ERROR_NUMBER:
            printf(FORMAT_OUTPUT_STRING_MEMORY_ERROR);
            break;
        case FORMAT_OUTPUT_STRING_WIDTH_ERROR_NUMBER:
            printf(FORMAT_OUTPUT_STRING_WIDTH_ERROR);
            break;
    }
}
