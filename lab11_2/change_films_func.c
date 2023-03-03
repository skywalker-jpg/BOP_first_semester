#include "change_films_func.h"

void sort_by_name(film **cinemas, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (strcmp(cinemas[j]->Name, cinemas[j + 1]->Name) > 0) {
                swap(cinemas[j], cinemas[j + 1]);
            }
        }
    }
}

void sort_cinemas(char *filename) {
    int count;
    film **cinemas = get_cinemas(filename, &count);
    if (cinemas == NULL) {
        return;
    }
    if (count == 0) {
        error_func(NO_CINEMAS_KEY);
        free_cinemas(cinemas, count);
        return;
    }
    sort_by_name(cinemas, count);
    if (write_cinemas_to_file(cinemas, count, filename) != 0) {
        error_func(BASIC_ERROR_KEY);
    }
    free_cinemas(cinemas, count);
}

int delete_cinemas(film ***cinemas, int *n, char *a) {
    int c = 0;
    for (int i = 0; i < *n; i++) {
        if (strcmp((*cinemas)[i]->Director, a) == 0) {
            delete_cinema((*cinemas), *n, i);
            (*n)--;
            if(i!=0) i--;
            c++;
        }
    }
    return c;
}

void delete_cinemas_by_artist(char *filename) {
    int count;
    film **cinemas = get_cinemas(filename, &count);
    if (cinemas == NULL) {
        return;
    }
    if (count == 0) {
        error_func(NO_CINEMAS_KEY);
        return;
    }
    output_directors(cinemas, count);
    printf("\nChoose director, who's cinema you wanna delete: ");
    char director[MAX_STR_LEN];
    int check_scanf = scanf("%100s", director);
    if (!check_scanf) {
        error_func(INPUT_ERROR_KEY);
        return;
    }
    int c = delete_cinemas(&cinemas, &count, director);
    if (write_cinemas_to_file(cinemas, count, filename) != 0) {
        error_func(BASIC_ERROR_KEY);
    }
    free_cinemas(cinemas, count);
    printf("Cinemas were deleted\n");
}