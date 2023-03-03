#ifndef INC_8_2_INPUT_FUNCTIONS_H
#define INC_8_2_INPUT_FUNCTIONS_H
#include <stdlib.h>
#include <stdio.h>
#include "string_func.h"
#define VALUE_OF_NUMBER_ERROR "Error: number of strings must be > 0\n"
#define STRING_ALLOCATION_ERROR "Error: memory was not allocated\n"
#define REPLACE_ALLOCATION_ERROR "Error: memory for replacing string was not allocated\n"
int input_string(char **str);
int input_count_strings(int * count_strings);
int input_list_strings(char *** list_of_strings, int count_strings);
int input_all(char ***list_of_strings, int *count_strings, char **replace, char **to_replace);
void freelist_of_strings(char ** list_of_strings, int count_strings);

#endif
