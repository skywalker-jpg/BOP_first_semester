#include "memory.h"

student *struct_memory_alloc(int n) {
    return (student*)malloc(n * sizeof(student));
}

void free_memory(student* person) {
    free(person);
}

