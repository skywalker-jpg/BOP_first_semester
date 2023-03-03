#ifndef LAB11_2_MEMORY_H
#define LAB11_2_MEMORY_H
#include "structure_operations.h"
#include "structure.h"
#include "stdlib.h"
film *allocate_struct();
film **allocate_cinemas(int n);
void free_struct(film *cinema);
void free_cinemas(film **cinemas, int n);
#endif
