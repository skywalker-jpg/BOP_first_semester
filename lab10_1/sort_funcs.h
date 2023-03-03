
#ifndef LAB10_1_SORT_FUNCS_H
#define LAB10_1_SORT_FUNCS_H
#include "structure.h"
#include "stdio.h"
#include "string.h"
#define MARKS_COUNT 5
void swap(student *pa, student *pb);
void find_min_mark(student *person);
int compare_surname(student *s1, student *s2);
void group_category(student *person, int n, int *index_5, int *index_4, int *index_3);
void sort_students_by_surname(student *person, int n);
int count_2(student *person);
void del_student(student *person, int n, int i);
void del_bad_students(student *person, int *n);
void calculate_average_score(student *person);


#endif
