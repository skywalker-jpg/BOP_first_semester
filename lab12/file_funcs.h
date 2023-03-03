
#ifndef LASTONE_FILE_FUNCS_H
#define LASTONE_FILE_FUNCS_H
#include "stdio.h"
#include "structure.h"
#include "template_funcs.h"
#include "string.h"
#include "program_funcs.h"
#define NO_FILMS_ERROR_KEY 2
#define NO_FILMS_ERROR "There are no films in the file\n"
#define FILE_ERROR_KEY 3
#define FILE_ERROR "Something is wrong with file\n"
#define WRONG_DATA_INPUT_ERROR_KEY 4
#define WRONG_DATA_INPUT_ERROR "Wrong data input\n"
void output_cinemas();
int get_file_size_in_bytes(FILE *pfile);
int add_cinema_to_file();
void sort_cinemas();
void set_file_size(FILE *pfile, int new_size);
void delete_cinemas_by_artist();
#endif //LASTONE_FILE_FUNCS_H
