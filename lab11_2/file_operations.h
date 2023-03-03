#ifndef LAB11_2_FILE_OPERATIONS_H
#define LAB11_2_FILE_OPERATIONS_H
#include "stdio.h"
#include "structure.h"
#include "structure_operations.h"
#include "change_films_func.h"
#include "structure.h"
int count_lines_in_file(char *filename);
void swap(film *cinema1, film *cinema2);
void delete_cinema(film **cinema, int n, int i);
#endif
