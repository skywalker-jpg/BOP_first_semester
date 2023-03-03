#include "file_operations.h"

int count_lines_in_file(char *filename) {
    FILE *p_file = fopen(filename, "r");
    if (p_file == NULL) {
        return 0;
    }
    int line_count = 0;
    char c;
    do {
        c = getc(p_file);
        if (c == '\n') {
            line_count++;
        }
    } while (c != EOF);
    rewind(p_file);
    c = getc(p_file);
    if (c != EOF && line_count == 0) {
        line_count++;
    }
    fclose(p_file);
    return line_count;
}

void swap(film *cinema1, film *cinema2) {
    film tmp = *cinema1;
    *cinema1 = *cinema2;
    *cinema2 = tmp;
}

void delete_cinema(film **cinema, int n, int i){
    for (int j = i; j < n - 1; j++) {
        cinema[j] = cinema[j + 1];
    }
}