#include "memory.h"

char* memory_string(int len){
    return (char*)malloc(len*sizeof(char));
}

char** memory_mass_strings(int number){
    return (char**)malloc(number*sizeof(char*));
}

void free_mas_strings(char** text){
    free(text);
}
