#ifndef PROCESS_H
#define PROCESS_H

#include "memory.h"
#include "string.h"
#include "errors.h"
#include "io.h"
#include <ctype.h>

int max_word_length_string(char* str);
int max_word_length_text(char** text, int number);
void format_output_string(char* str, int width, int max_len);
void changing_string(char* str, int width);
int count_spaces(char* str);
void check_and_do(int *word_len, int *cur_len, int width, char* outp_str, char* word);
void format_output_text(char **text, int number, int width, int max_len);


#endif // PROCESS_H
