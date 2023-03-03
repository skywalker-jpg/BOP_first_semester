#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>

char* memory_string(int len);
char** memory_mass_strings(int number);
void free_mas_strings(char** text);

#endif // MEMORY_H
