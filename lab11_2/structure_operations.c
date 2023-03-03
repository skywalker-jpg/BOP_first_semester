#include "structure_operations.h"

int append_cinema_to_file(film *cinema, char *filename) {
    FILE *p_file = fopen(filename, "a");
    if (p_file == NULL) {
        return -1;
    }
    int is_success_write = (fprintf(p_file, "%s %s %d %d\n", cinema->Name, cinema->Director, cinema->Duration, cinema->Rank) >= 0);
    fclose(p_file);
    if (is_success_write) {
        return 0;
    }
    else
        return -1;
}

int write_cinemas_to_file(film **cinemas, int n, char *filename) {
    FILE *p_file = fopen(filename, "w");
    if (p_file == NULL) {
        return -1;
    }
    fclose(p_file);
    int is_success_write = 0;
    for (int i = 0; i < n && is_success_write == 0; i++) {
        int check = append_cinema_to_file(cinemas[i], filename);
        is_success_write += check;
    }
    if (is_success_write == 0)
        return 0;
    else
        return -1;
}

film *input_cinema() {
    film *cinema = allocate_struct();
    if (cinema == NULL) {
        return NULL;
    }
    printf("Input cinema name:");
    int is_succes_input = scanf("%s", cinema->Name) == 0;
    printf("Input cinema director:");
    is_succes_input += scanf("%s", cinema->Director) == 0;
    printf("Input cinema duration:");
    is_succes_input += scanf("%d", &(cinema->Duration)) == 0;
    printf("Input cinema rank:");
    is_succes_input += scanf("%d", &(cinema->Rank)) == 0;
    if (is_succes_input > 0) {
        return NULL;
    }
    return cinema;
}

int add_cinema_to_file(char *filename) {
    film *cinema = input_cinema();
    if (cinema == NULL) {
        return -1;
    }
    return append_cinema_to_file(cinema, filename);
}

int read_cinema(film *cinema, FILE *p_file) {
    int is_success_read = (fscanf(p_file, "%s %s %d %d", cinema->Name, cinema->Director, &(cinema->Duration), &(cinema->Rank)) == 4);
    if (is_success_read)
        return 0;
    else
        return 1;
}

int read_cinemas_from_file(film **cinemas, int n, char *filename) {
    FILE *p_file = fopen(filename, "r");
    if (p_file == NULL) {
        return -1;
    }
    int is_success_read = 0;
    for (int i = 0; i < n && is_success_read == 0; i++) {
        is_success_read += read_cinema(cinemas[i], p_file);
    }
    fclose(p_file);
    if (is_success_read != 0)
        return 0;
    else
        return -1;
}

void show_cinema(film *cinema) {
    printf("Name: %s\nDirector: %s\nDuration: %d\nRank: %d\n\n", cinema->Name, cinema->Director, cinema->Duration, cinema->Rank);
}

void show_cinemas(film **cinemas, int n) {
    printf("\nfilm:\n");
    for (int i = 0; i < n; i++) {
        show_cinema(cinemas[i]);
    }
}

film **get_cinemas(char *filename, int *number) {
    *number = count_lines_in_file(filename);
    film **cinemas = allocate_cinemas(*number);
    if (cinemas == NULL) {
        error_func(MEMORY_ALLOC_ERROR_KEY);
        return NULL;
    }
    if (read_cinemas_from_file(cinemas, *number, filename) == 0) {
        error_func(READING_ERROR_KEY);
        return NULL;
    }
    else
        return cinemas;
}

void output_cinemas(char *filename) {
    int number;
    film **cinemas = get_cinemas(filename, &number);
    if (cinemas == NULL) {
        return;
    }
    if (number == 0) {
        error_func(NO_CINEMAS_KEY);
        free_cinemas(cinemas, number);
        return;
    }
    show_cinemas(cinemas, number);
    free_cinemas(cinemas, number);
}

void output_directors(film **cinemas, int n) {
    printf("Directors:");
    for (int i = 0; i < n; i++) {
        printf(" %s", cinemas[i]->Director);
    }
}