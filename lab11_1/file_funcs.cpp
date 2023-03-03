#include "file_funcs.h"
int count_strings_number(FILE *old_file) {
    int strings_count = 0;
    char c;
    do {
        c = getc(old_file);
        if (c == '\n') {
            strings_count++;
        }
    } while (c != EOF);
    rewind(old_file);
    c = getc(old_file);
    if (c != EOF && strings_count == 0) {
        strings_count++;
    }
    return strings_count + 1;
}

int *count_strings_length(FILE *old_file, int strings_count) {
    int *array_of_strs_lens = (int*)malloc(strings_count * sizeof(int));
    if (array_of_strs_lens == NULL) {
        return NULL;
    }
    char c;
    int i = 0, curr_len = 0;
    while (!(feof(old_file))) {
        c = fgetc(old_file);
        curr_len++;
        if (c == '\n') {
            array_of_strs_lens[i] = curr_len;
            curr_len = 0;
            i++;
        }
    }
    array_of_strs_lens[strings_count - 1] = curr_len;
    return array_of_strs_lens;
}

int store_strings_from_file_to_array(char **array_of_strs, FILE *old_file, int strings_count) {
    int *array_of_strs_lens = count_strings_length(old_file, strings_count);
    if (array_of_strs_lens == NULL) {
        printf(MEMORY_ALLOCATION_ERROR);
        return 0;
    }
    rewind(old_file);
    for (int i = 0; i < strings_count; i++) {
        array_of_strs[i] = str_memory_alloc(array_of_strs_lens[i]);
        if (array_of_strs[i] == NULL) {
            printf(MEMORY_ALLOCATION_ERROR);
            return 0;
        }
        char string[array_of_strs_lens[i]];
        if (fgets(string, array_of_strs_lens[i] + 1, old_file) != NULL) {
            strcpy(array_of_strs[i], string);
        }
    }
    return 1;
}

void output_array_of_strings(char **array_of_strs, int strings_count) {
    for (int i = 0; i < strings_count; i++) {
        printf("%s", array_of_strs[i]);
    }
}

void delete_string(char **array_of_strs, int strings_count, int i) {
    for (int j = i; j < strings_count - 1; j++) {
        *(array_of_strs + j) = *(array_of_strs + j + 1);
    }
}

void delete_empty_strings(char **array_of_strs, int *strings_count) {
    for (int i = 0; i < *strings_count; i++) {
        if ((strcmp(array_of_strs[i], "\n") == 0 || strcmp(array_of_strs[i], "") == 0)) {
            delete_string(array_of_strs, *strings_count, i);
            (*strings_count)--;
            i--;
        }
    }
}

int add_numbers_to_strings(char **array_of_strs, int string_count) {
    for (int i = 0; i < string_count; i++) {
        char *new_string = str_memory_alloc((int)strlen(array_of_strs[i]) + 3);
        if (new_string == NULL) {
            printf(MEMORY_ALLOCATION_ERROR);
            return 0;
        }
        sprintf(new_string, "%d. ", i + 1);
        strcat(new_string, array_of_strs[i]);
        array_of_strs[i] = new_string;
    }
    return 1;
}

int write_text_to_new_file(char **array_of_strs, FILE *new_file, int strings_count) {
    for (int i = 0; i < strings_count; i++) {
        if (fputs(array_of_strs[i], new_file) == EOF) {
            return 0;
        }
    }
    return 1;
}