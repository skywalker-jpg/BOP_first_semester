#ifndef lab11_FILE_FUNCS_H
#define lab11_FILE_FUNCS_H
#include "string.h"
#include "stdlib.h"
#include "memory.h"
#include "stdio.h"
#include <ctype.h>
#define FILE_IS_EMPTY_ERROR "There are no strings in file"
#define FILE_IS_EMPTY_ERROR_KEY 1
#define MEMORY_ALLOCATION_ERROR "Error: memory was not allocated\n"
#define MEMORY_ALLOCATION_ERROR_KEY 2
#define FILE_DOES_NOT_EXIST "File does not exist"
#define FILE_DOES_NOT_EXIST_KEY 3
int count_strings_number(FILE *old_file);
int *count_strings_length(FILE *old_file, int strings_count);
int file_to_array(char **array_of_str, FILE *old_file, int strings_count);
void output_array_of_strings(char **array_of_strs, int strings_count);
void delete_string(char **array_of_strs, int strings_count, int i);
void delete_empty_strings(char **array_of_strs, int *strings_count);
int add_numbers(char **array_of_strs, int string_count);
int write_text_to_new_file(char **array_of_strs, FILE *new_file, int strings_count);
int file_check(char* filename);
void error_func(int n);
#endif
