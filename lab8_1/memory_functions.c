#include "main_header.h"
void free_memory(char *str) {
    free(str);
}
char *memory_allocation(int length) {
    return (char *) malloc(length * sizeof(char));
}

words *memory_alloc_for_words(){
    return (words *) malloc(sizeof(words));
}