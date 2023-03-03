#include "input_output.h"

int check_input_n(int *n) {
    int check_scanf = scanf("%d", n);
    if (!check_scanf || *n < 1) {
        printf(OUTPUT_NUMBER_OF_STUDENTS_ERROR);
        return WRONG_INPUT;
    }
    return CORRECT_INPUT;
}

int check_mark(student *person, int i) {
    if (person->marks[i] < 1 || person->marks[i] > 5) {
        printf(OUTPUT_MARK_ERROR);
        return WRONG_INPUT;
    }
    return CORRECT_INPUT;
}

int input_student(student *person) {
    printf(INPUT_SURNAME_STRING);
    scanf("%s", person->surname);
    printf(INPUT_MARKS_STRING);
    int flag = 1;
    for (int j = 0; j < MARKS_COUNT; j++) {
        scanf("%d", &person->marks[j]);
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
    printf("%s,", person->surname);
    printf(" marks:");
    for (int i = 0; i < MARKS_COUNT; i++) {
        printf(" %d", person->marks[i]);
    }
    printf(", Average = %g", person->avg_score);
    printf("\n");
}

void output_structure(student *person, int n) {
    printf(OLD_OUTPUT_STRING);
    for (int i = 0; i < n; i++) {
        output_student(person + i);
    }
}

void output_sorted_groups(student *person, int n) {
    printf(NEW_OUTPUT_STRING);
    int min_mark_n = 0;
    for (int i = 0; i < n; i++) {
        if ((person + i)->min_mark != min_mark_n) {
            printf("Group: %d\n", (person + i)->min_mark);
            min_mark_n = (person + i)->min_mark;
        }
        output_student(person + i);
    }
}