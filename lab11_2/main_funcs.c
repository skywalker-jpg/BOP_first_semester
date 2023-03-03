
#include "main_funcs.h"
int input_option() {
    int option;
    int check_scanf = scanf("%d", &option);
    if (!check_scanf) {
        printf("Input error\n");
        return 0;
    }
    return option;
}

void output_options() {
    printf("Choose option (1 to 5):\n");
    printf("1 - add cinema to file\n");
    printf("2 - output films\n");
    printf("3 - sort cinemas by name\n");
    printf("4 - delete films by chosen Director\n");
    printf("5 - close menu\n");
}

void error_func(int n){
    if(n==NO_CINEMAS_KEY){
        printf(NO_CINEMAS);
    }
    else if(n==INPUT_ERROR_KEY){
        printf(INPUT_ERROR);
    }
    else if(n==BASIC_ERROR_KEY){
        printf(BASIC_ERROR);
    }
    else if(n==MEMORY_ALLOC_ERROR_KEY){
        printf(MEMORY_ALLOC_ERROR);
    }
    else if(n==READING_ERROR_KEY){
        printf(READING_ERROR);
    }
}