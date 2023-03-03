#include "mylib.h"

int main() {
    if(file_check(OLD_FILENAME)==0){
        error_func(FILE_DOES_NOT_EXIST_KEY);
        return 0;
    }
    FILE *old_file = fopen(OLD_FILENAME, "r");
    int strings_count = count_strings_number(old_file);
    if (strings_count==0) {
        error_func(FILE_IS_EMPTY_ERROR_KEY);
        return 0;
    }
    rewind(old_file);
    char **array_of_str = array_of_str_memory_alloc(strings_count);
    if (array_of_str == NULL) {
        error_func(MEMORY_ALLOCATION_ERROR_KEY);
        return 0;
    }
    if (file_to_array(array_of_str, old_file, strings_count)) {
        delete_empty_strings(array_of_str, &strings_count);
        if (!add_numbers(array_of_str, strings_count)) {
            free_array_of_str(array_of_str, strings_count);
            return 0;
        }
        output_array_of_strings(array_of_str, strings_count);
        fclose(old_file);
    }
    if(file_check(NEW_FILENAME)==0){
        error_func(FILE_DOES_NOT_EXIST_KEY);
        return 0;
    }
    FILE *new_file = fopen(NEW_FILENAME, "w");
    if (write_text_to_new_file(array_of_str, new_file, strings_count)) {
        fclose(new_file);
    }
    fclose(new_file);
    free_array_of_str(array_of_str, strings_count);
    return 0;
}
