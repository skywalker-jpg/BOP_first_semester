#ifndef INC_8_2_CHANGE_STRING_H
#define INC_8_2_CHANGE_STRING_H
#include <stdio.h>
#include "string_func.h"
int replace_string(const char * dest, const char * src, char ** str);
void decrease_string(char * str);
void increase_string(char * str);
void find_surname(char * str, size_t * end, size_t * begin);

#endif
