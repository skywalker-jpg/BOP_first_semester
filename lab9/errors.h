#ifndef ERRORS_H
#define ERRORS_H
#include <stdio.h>

#define FORMAT_OUTPUT_STRING_MEMORY_ERROR_NUMBER 3
#define FORMAT_OUTPUT_STRING_MEMORY_ERROR "Error: failed to allocate memory"
#define FORMAT_OUTPUT_STRING_WIDTH_ERROR_NUMBER 2
#define FORMAT_OUTPUT_STRING_WIDTH_ERROR "Error: invalid width"

void errors_func(int problem_code);


#endif // ERRORS_H
