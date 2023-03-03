#ifndef lab11_MEMORY_H
#define lab11_MEMORY_H
#include "stdlib.h"
void free_str(char *str);
void free_array_of_str(char **arr, int strings_count);
char *str_memory_alloc(int n);
char **array_of_str_memory_alloc(int strings_count);
int* int_memory_alloc(int n);
#endif