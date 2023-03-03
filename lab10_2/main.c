#include "mylib.h"
int main() {
    int n;
    printf(INPUT_NUMBER_OF_STUDENTS_STRING);
    if (!check_input_n(&n)){
        return 0;
    }
    student *person = struct_memory_alloc(n);
    if (person != NULL) {
        int flag;
        flag = input_group(person, n);
        if (flag) {
            output_structure(person, n);
            group_category(person, n);
            sort_surnames(person, n);
            del_bad_student(person, &n);
            output_sorted_groups(person, n);
            free_memory(person);
        }
    }
    else {
        error(Memory_allocation_error_key);
    }
    return 0;
}
