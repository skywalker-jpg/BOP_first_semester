#include "mystring.h"

int main() {
    int count_strings;
    char **list_string = NULL;
    char *to_replace;
    char *replace;
    if (input_all(&list_string, &count_strings, &replace, &to_replace)) {
        for (int i = 0; i < count_strings; i++) {
            printf("Enter current string:%s\n", list_string[i]);
            replace_string(to_replace, replace, list_string + i);
            printf("Changed string:%s\n", list_string[i]);
        }
        free(replace);
        free(to_replace);
        freelist_of_strings(list_string, count_strings);
        free(list_string);
    }
    return 0;
}
