#ifndef LAB11_2_STRUCTURE_OPERATIONS_H
#define LAB11_2_STRUCTURE_OPERATIONS_H
#include "stdio.h"
#include "memory.h"
#include "file_operations.h"
#include "structure.h"
#include "main_funcs.h"
#define MEMORY_ALLOC_ERROR "Memory allocation error!\n"
#define MEMORY_ALLOC_ERROR_KEY 4
#define READING_ERROR "Reading error\n"
#define READING_ERROR_KEY 5
#define MAX_STR_LEN 100

int append_cinema_to_file(film *cinema, char *filename);
int write_cinemas_to_file(film **cinemas, int n, char *filename);
film *input_cinema();
int add_cinema_to_file(char *filename);
int read_cinema(film *cinema, FILE *p_file);
int read_cinemas_from_file(film **cinemas, int n, char *filename);
void show_cinema(film *cinema);
void show_cinemas(film **cinemas, int n);
film **get_cinemas(char *filename, int *number);
void output_cinemas(char *filename);
void output_directors(film **cinemas, int n);
#endif
