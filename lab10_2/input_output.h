#ifndef LAB10_1_INPUT_OUTPUT_H
#define LAB10_1_INPUT_OUTPUT_H
#include "stdio.h"
#include "structure.h"
#include "sort_funcs.h"
#include "define.h"
#include "error_funcs.h"
#define WRONG_INPUT 0
#define CORRECT_INPUT 1
int check_input_n(int *n);
int check_mark(student *person, int i);
int input_student(student *person);
int input_group(student *person, int n);
void output_student(student *person);
void output_structure(student *person, int n);
void output_sorted_groups(student *person, int n);

#endif
