#include "mylib.h"
int main() {
    int n;
    printf(INPUT_NUMBER_OF_STUDENTS_STRING);
    if (!check_input_n(&n)) {
        return 0;
    }
    student *person = struct_memory_alloc(n);
    if (person != NULL) {
        if (input_group(person, n)) {
            int index_5 = 0, index_4 = 0, index_3 = 0;
            output_structure(person, n);
            group_category(person, n, &index_5, &index_4, &index_3);
            sort_students_by_surname(person, index_5);
            sort_students_by_surname(person + index_5, n - index_5);
            sort_students_by_surname(person + index_4, n - index_4);
            sort_students_by_surname(person + index_3, n - index_3);
            del_bad_students(person, &n);
            output_sorted_groups(person, n);
            free_memory(person);
        }
    }
    else {
        printf(MEMORY_ALLOCATION_ERROR);
    }
    return 0;
}
