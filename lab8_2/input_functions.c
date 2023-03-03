
#include "input_functions.h"

int input_string(char ** str) {
    char *buff_str;
    char buffSymbol;
    size_t i = 2;
    buffSymbol = getchar();
    while (buffSymbol != '\n') {
        buff_str = (*str);
        (*str) = (char*)malloc(i * sizeof(char));
        if (!(*str)) {
            if (i != 2) {
                free(buff_str);
            }
            return 0;
        }
        if (i != 2) {
            my_strcpy((*str), buff_str);
            (*str)[i - 2] = buffSymbol;
            (*str)[i - 1] = '\0';
            free(buff_str);
        } else {
            (*str)[0] = buffSymbol;
            (*str)[1] = '\0';
        }
        i++;
        buffSymbol = getchar();
    }
    return 1;
}

int input_count_strings(int * count_strings) {
    char endl;
    if (scanf("%d%c", count_strings, &endl)) {
        if (*count_strings >= 1 && endl == '\n')
            return 1;
    }
    return 0;
}

int input_list_string(char *** list_of_strings, int count_strings) {
    int result = 1;
    *list_of_strings = (char **)malloc(sizeof(char *) * count_strings);
    if (!(*list_of_strings))
        return 0;

    for (int i = 0; i < count_strings; i++) {
        if (!input_string(*list_of_strings + i)) {
            freelist_of_strings(*list_of_strings, i);
            result = 0;
            break;
        } else {
            if (count_words(*(*list_of_strings + i), " ") != 3) {
                freelist_of_strings(*list_of_strings, i + 1);
                free(*list_of_strings);
                result = 0;
                break;
            }
        }
    }
    return result;
}

int check_error(int result) {
    switch (result) {
        case ERROR_INPUT_COUNT_STRINGS:
            printf(VALUE_OF_NUMBER_ERROR);
            break;
        case ERROR_INPUT_STRINGS:
            printf(STRING_ALLOCATION_ERROR);
            break;
        case ERROR_INPUT_REPLACE_STRING: {
            printf(REPLACE_ALLOCATION_ERROR);
        }
    }
    if (result) {
        result = 0;
    } else {
        result = 1;
    }
    return result;
}

int input_all(char *** list_of_stringss, int * countStrings, char ** replace, char ** to_replace) {
    int result = 0;
    printf("Enter number of strings\n");
    if (input_count_strings(countStrings)) {
        printf("Enter strings\n");
        if (input_list_string(list_of_stringss, *countStrings)) {
            printf("Enter suf1\n");
            if (!input_string(replace)) {
                result = ERROR_INPUT_REPLACE_STRING;
            }
            if (!result)
                printf("Enter suf2\n");
            if (result || !input_string(to_replace)) {
                if (!result)
                    free(replace);
                freelist_of_strings(*list_of_stringss, *countStrings);
                result = ERROR_INPUT_REPLACE_STRING;
            }
        } else {
            result = ERROR_INPUT_STRINGS;
        }
    } else {
        result = ERROR_INPUT_COUNT_STRINGS;}

    result = check_error(result);
    return result;
}

void freelist_of_strings(char ** list_of_strings, int count_strings) {
    for (int i = 0; i < count_strings; i++)
        free(list_of_strings[i]);
}

