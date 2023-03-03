#include "main_header.h"
int input_string(char **str) {
    char *cur_str;
    char cur_symbol;
    int i = 2;
    int symb_count = 2;
    cur_symbol = getchar();
    if (cur_symbol == '\n') {
        return 0;
    }
    while (cur_symbol != '\n') {
        cur_str = (*str);
        (*str) = memory_allocation(i);
        if (!(*str)) {
            if (symb_count != 2) {
                cur_str=NULL;
            }
            return 0;
        }
        if (symb_count != 2) {
            strcpy((*str), cur_str);
            (*str)[symb_count - 2] = cur_symbol;
            (*str)[symb_count - 1] = '\0';
            cur_str=NULL;
        } else {
            (*str)[0] = cur_symbol;
            (*str)[1] = '\0';
        }
        i++;
        symb_count++;
        cur_symbol = getchar();
    }
    return 1;
}


char *input_text_data() {
    char *new_line;
    char *text = NULL;
    char *temp = NULL;
    int check = input_string(&new_line);
    int flag;
    while (check) {
        temp=NULL;
        char last_symbols[] = ".,?!;: ";
        flag = 1;
        if (strchr(last_symbols, new_line[strlen(new_line) - 1])) {
            flag = 0;
        }
        if (text != NULL) {
            temp = memory_allocation((int) strlen(text));
            if (temp == NULL){
                return NULL;
            }
            strcpy(temp, text);
            text=NULL;
            text = memory_allocation((int) strlen(temp) + (int) strlen(new_line) + flag);
            strcpy(text, temp);
            strcat(text, new_line);
        } else {
            text = memory_allocation((int) strlen(new_line) + flag);
            strcpy(text, new_line);
        }
        if (flag) {
            strcat(text, " ");
        }
        free(new_line);
        check = input_string(&new_line);
    }
    temp=NULL;
    return text;
}

