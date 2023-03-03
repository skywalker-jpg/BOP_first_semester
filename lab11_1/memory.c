#include "memory.h"

void free_str(char *str) {
    free(str);
}
void free_array_of_str(char **arr, int strings_count) {
    free(arr);
}
char *str_memory_alloc(int n) {
    return (char*)malloc(n * sizeof(char));
}
char **array_of_str_memory_alloc(int strings_count) {
    return (char**)malloc(strings_count * sizeof(char*));
}

int* int_memory_alloc(int n){
    return (int*)malloc(n * sizeof(int));
}