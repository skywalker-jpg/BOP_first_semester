#ifndef IO_H
#define IO_H

#include <stdio.h>
#include "memory.h"
#include <string.h>
#include "errors.h"

#define SUCCES_WIDTH 1
#define FORMAT_OUTPUT_HELLO_STRING_TEXT "Enter text, please: "
#define FORMAT_OUTPUT_HELLO_WIDTH "\nEnter width, please: "

char* input_str();
char** input_text(int *number);
int input_width(int *width, int min_length);
void output_string(char* str);
#endif // IO_H
