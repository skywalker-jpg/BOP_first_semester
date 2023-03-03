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
    rewind(old_file);
    if (c == EOF){
        return 0;
    }
    else{
        return strings_count+1;
    }
}

int *count_strings_length(FILE *old_file, int strings_count) {
    int *array_of_str_lens = int_memory_alloc(strings_count);
    if (array_of_str_lens == NULL) {
        return NULL;
    }
    char c;
    int i = 0, curr_len = 0;
    while (!(feof(old_file))) {
        c = fgetc(old_file);
        curr_len++;
        if (c == '\n') {
            array_of_str_lens[i] = curr_len+1;
            curr_len = 0;
            i++;
        }
    }
    array_of_str_lens[strings_count - 1] = curr_len;
    return array_of_str_lens;
}

int file_to_array(char **array_of_str, FILE *old_file, int strings_count) {
    int *array_of_str_lens = count_strings_length(old_file, strings_count);
    if (array_of_str_lens == NULL) {
        printf(MEMORY_ALLOCATION_ERROR);
        return 0;
    }
    rewind(old_file);
    for (int i = 0; i < strings_count; i++) {
        array_of_str[i] = str_memory_alloc(array_of_str_lens[i]);
        if (array_of_str[i] == NULL) {
            printf(MEMORY_ALLOCATION_ERROR);
            return 0;
        }
        char string[array_of_str_lens[i]];
        if (fgets(string, array_of_str_lens[i], old_file) != NULL) {
            strcpy(array_of_str[i], string);
        }
        else{
            strcpy(array_of_str[i], "\0");
        }
    }
    fclose(old_file);
    return 1;
}

void output_array_of_strings(char **array_of_str, int strings_count) {
    for (int i = 0; i < strings_count; i++) {
        printf("%s", array_of_str[i]);
    }
}

void delete_string(char **array_of_str, int strings_count, int i) {
    for (int j = i; j < strings_count - 1; j++) {
        *(array_of_str + j) = *(array_of_str + j + 1);
    }
}

void delete_empty_strings(char **array_of_str, int *strings_count) {
    for (int i = 0; i < *strings_count; i++) {
        if ((strcmp(array_of_str[i], "\n") == 0 || strlen(array_of_str[i]) == 0)) {
            delete_string(array_of_str, *strings_count, i);
            (*strings_count)--;
            i--;
        }
    }
}

int add_numbers(char **array_of_str, int string_count) {
    for (int i = 0; i < string_count; i++) {
        char c;
        itoa(i,&c,10);
        char *new_string = str_memory_alloc((int)strlen(array_of_str[i]) + strlen(&c));
        if (new_string == NULL) {
            printf(MEMORY_ALLOCATION_ERROR);
            return 0;
        }
        sprintf(new_string, "%d. ", i + 1);
        strcat(new_string, array_of_str[i]);
        array_of_str[i] = new_string;
    }
    return 1;
}

int write_text_to_new_file(char **array_of_str, FILE *new_file, int strings_count) {
    for (int i = 0; i < strings_count; i++) {
        if (fputs(array_of_str[i], new_file) == EOF) {
            return 0;
        }
    }
    return 1;
}

int file_check(char* filename){
    FILE *file = fopen(filename, "r");
    if(file==NULL) return 0;
    rewind(file);
    return 1;
}

void error_func(int n){
    switch (n) {
        case FILE_IS_EMPTY_ERROR_KEY:
            printf(FILE_IS_EMPTY_ERROR);
            break;
        case MEMORY_ALLOCATION_ERROR_KEY:
            printf(MEMORY_ALLOCATION_ERROR);
            break;
        case FILE_DOES_NOT_EXIST_KEY:
            printf(FILE_DOES_NOT_EXIST);
            break;
        default:;
    }
}