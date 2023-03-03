#ifndef LAB11_2_CHANGE_FILMS_FUNCS_H
#define LAB11_2_CHANGE_FILMS_FUNCS_H
#include "stdio.h"
#include "structure_operations.h"
#include "string.h"
#include "structure.h"
#include "memory.h"
#include "main_funcs.h"
#define NO_CINEMAS_KEY 0
#define NO_CINEMAS "No cinemas in file\n"
#define INPUT_ERROR_KEY 1
#define INPUT_ERROR "Input_error\n"
#define BASIC_ERROR_KEY 2
#define BASIC_ERROR "Error\n"
void swap(film *cinema1, film *cinema2);
void sort_by_name(film **cinemas, int n);
void sort_cinemas(char *filename);
void delete_cinema(film **cinema, int n, int i);
int delete_cinemas(film ***cinemas, int *n, char *a);
void delete_cinemas_by_artist(char *filename);
#endif
