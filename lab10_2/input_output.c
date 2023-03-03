#include "input_output.h"

int check_input_n(int *n) {
    int check_scanf = scanf(double1, n);
    if (!check_scanf || *n < 1) {
        error(number_of_students_error_key);
        return WRONG_INPUT;
    }
    return CORRECT_INPUT;
}

int check_mark(student *person, int i) {
    if (person->marks[i] < 1 || person->marks[i] > 5) {
        error(mark_error_key);
        return 0;
    }
    return 1;
}

int input_student(student *person) {
    printf(enter_surname);
    scanf(str1, person->surname);
    printf(enter_marks);
    int flag = 1;
    for (int j = 0; j < MARKS_COUNT; j++) {
        scanf(int1, &person->marks[j]);
        flag = check_mark(person, j);
        if (!flag)
            break;
    }
    find_min_mark(person);
    calculate_average_score(person);
    return flag;
}

int input_group(student *person, int n) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        flag = input_student(person + i);
        if (!flag)
            break;
    }
    return flag;
}

void output_student(student *person) {
    printf(str1, person->surname);
    printf(marks1);
    for (int i = 0; i < MARKS_COUNT; i++) {
        printf(int1, person->marks[i]);
    }
    printf(avarage, person->avg_score);
}

void output_structure(student *person, int n) {
    printf(output);
    for (int i = 0; i < n; i++) {
        output_student(person + i);
    }
}

void output_sorted_groups(student *person, int n) {
    printf(new_output);
    int min_mark_n = 0;
    for (int i = 0; i < n; i++) {
        if (min_mark_n != (person+i)->min_mark) {
            printf(group, (person+i)->min_mark);
            min_mark_n = (person+i)->min_mark;
        }
        output_student(person + i);
    }
}