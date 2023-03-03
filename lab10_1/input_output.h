
#ifndef LAB10_1_INPUT_OUTPUT_H
#define LAB10_1_INPUT_OUTPUT_H
#include "stdio.h"
#include "structure.h"
#include "sort_funcs.h"
#define WRONG_INPUT 0
#define CORRECT_INPUT 1
#define OUTPUT_NUMBER_OF_STUDENTS_ERROR "\nNumber of students error: (number gotta be >= 1)\n"
#define OUTPUT_MARK_ERROR "\nMark error: mark gotta be >= 1 and <= 5\n"
#define INPUT_SURNAME_STRING "Enter surname:\n"
#define INPUT_MARKS_STRING "Enter marks: "
#define OLD_OUTPUT_STRING "\n\noutput:\n"
#define NEW_OUTPUT_STRING "\n\nnew output:\n"
int check_input_n(int *n);
int check_mark(student *person, int i);
int input_student(student *person);
int input_group(student *person, int n);
void output_student(student *person);
void output_structure(student *person, int n);
void output_sorted_groups(student *person, int n);

#endif
