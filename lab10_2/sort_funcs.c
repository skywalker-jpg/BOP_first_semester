#include "sort_funcs.h"
void swap(student *pa, student *pb) {
    student tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

void find_min_mark(student *person) {
    int min_mark = person->marks[0];
    for (int i = 0; i < MARKS_COUNT; i++) {
        if (person->marks[i] < min_mark) {
            min_mark = person->marks[i];
        }
    }
    person->min_mark = min_mark;
}

int compare_surname(student *s1, student *s2) {
    return strcmp(s1->surname, s2->surname) > 0;
}

void group_category(student *person, int n) {
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if ((*(person + j + 1)).min_mark > (*(person + j)).min_mark) {
                swap(person + j, person + j + 1);
            }
        }
    }
}

void sort_surnames(student *person, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (compare_surname(person + j, person + j + 1)) {
                swap(person + j, person + j + 1);
            }
        }
    }
}

int count_2(student *person) {
    int count = 0;
    for (int i = 0; i < MARKS_COUNT; i++) {
        if (person->marks[i] == 2) {
            count++;
        }
    }
    return count;
}

void del_student(student *person, int n, int i) {
    for (int j = i; i < n - 2; i++) {
        *(person + i) = *(person + i + 1);
    }
}

void del_bad_student(student *person, int *n) {
    for (int i = 0; i < *n; i++) {
        if (count_2(person + i) > 2) {
            del_student(person, *n, i);
            (*n)--;
        }
    }
}

void calculate_average_score(student *person) {
    double summ = 0;
    for (int i = 0; i < MARKS_COUNT; i++) {
        summ += person->marks[i];
    }
    person->avg_score = summ / MARKS_COUNT;
}
