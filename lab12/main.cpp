#include "header.h"
int main() {
    output_options();
    int option = input_option();
    while (option != 5) {
        if (option < 1 || option > 5) {
            printf(CHOOSING_OPTION_ERROR);
            break;
        }
        if (option == 1) {
            int flag=add_cinema_to_file();
            if (flag==0) break;
        }
        if (option == 2) {
            output_cinemas();
        }
        if (option == 3) {
            sort_cinemas();
        }
        if (option == 4) {
            delete_cinemas_by_artist();
        }
        printf(CHOOSE_NEXT_OPTION_STRING);
        option = input_option();
    }
    printf(CLOSE_MENU_STRING);
    return 0;
}
