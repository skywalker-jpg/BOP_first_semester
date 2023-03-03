
#ifndef LAB10_1_SORT_FUNCS_H
#define LAB10_1_SORT_FUNCS_H
#include "structure.h"
#include "string.h"
#include "define.h"
void swap(student *pa, student *pb);
void find_min_mark(student *person);
int compare_surname(student *s1, student *s2);
void group_category(student *person, int n);
void sort_surnames(student *person, int n);
int count_2(student *person);
void del_student(student *person, int n, int i);
void del_bad_student(student *person, int* n);
void calculate_average_score(student *person);


#endif
