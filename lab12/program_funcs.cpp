#include "program_funcs.h"

void error_func(int n){
    if(n==INPUT_ERROR_KEY){
        printf(INPUT_ERROR);
    }
    if(n==NO_FILMS_ERROR_KEY){
        printf(NO_FILMS_ERROR);
    }
    if(n==FILE_ERROR_KEY){
        printf(FILE_ERROR);
    }
    if(n==WRONG_DATA_INPUT_ERROR_KEY)
        printf(WRONG_DATA_INPUT_ERROR);
}

int input_option() {
    int option;
    int check_scanf = scanf("%d", &option);
    if (!check_scanf) {
        error_func(INPUT_ERROR_KEY);
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
