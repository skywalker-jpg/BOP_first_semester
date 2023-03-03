#include "memory.h"

film *allocate_struct() {
    return (film*)malloc(sizeof(film));
}

film **allocate_cinemas(int n) {
    film **cinemas = (film**)malloc(n * sizeof(film*));
    if (cinemas == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        cinemas[i] = allocate_struct();
        if (cinemas[i] == NULL) {
            return NULL;
        }
    }
    return cinemas;
}

void free_struct(film *cinema) {
    free(cinema);
}

void free_cinemas(film **cinemas, int n) {
    for (int i = 0; i < n; i++) {
        free_struct(cinemas[i]);
    }
    free(cinemas);
}