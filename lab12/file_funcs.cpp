#include "file_funcs.h"
#include "header.h"
void print_film(const film *current_film)
{
    printf("Film name: %s\n", current_film->film_name);
    printf("Director: %s\n", current_film->director);
    printf("Duration: %d\n", current_film->duration);
    printf("Rank: %d\n", current_film->rank);
}

void output_cinemas()
{
    FILE *pfile=fopen(FILENAME,"rb");
    if(pfile!=NULL) {
        int film_count = get_records_count_in_file<film>(pfile);
        for (int i = 0; i < film_count; i++) {
            film current_film = read_record_from_file<film>(pfile, i);
            print_film(&current_film);
            printf("\n");
        }
        if (film_count == 0) {
            error_func(NO_FILMS_ERROR_KEY);
        }
    }
    else{
        error_func(FILE_ERROR_KEY);
    }
}

int add_cinema_to_file(){
    int flag=0;
    film current_film;
    FILE *pfile=fopen(FILENAME,"ab");
    if(pfile!=NULL) {
        printf("Input name of the film\n");
        flag += scanf("%s", current_film.film_name);
        printf("\nInput director of the film\n");
        flag += scanf("%s", current_film.director);
        printf("\nInput duration of the film\n");
        flag += scanf("%d", &current_film.duration);
        printf("\nInput rank of the film\n");
        flag += scanf("%d", &current_film.rank);
        if (flag == 4) {
            fwrite(&current_film, sizeof(film), 1, pfile);
            return 1;
        } else {
            error_func(WRONG_DATA_INPUT_ERROR_KEY);
            return 0;
        }
    }
    else{
        error_func(FILE_ERROR_KEY);
    }
    fclose(pfile);
}

int compare_films_by_director(const film *cinema1, const film *cinema2){
    return (strcmp(cinema1->director, cinema2->director) < 0) ? (1) : (0);
}

int compare_films_by_rank(const film *cinema1, const film *cinema2)
{
    return (cinema1->rank < cinema2->rank) ? (1) : (0);
}

void sort_cinemas(){
    int n;
    FILE *pfile=fopen(FILENAME,"r+b");
    if(pfile!=NULL) {
        printf("\n1-sort by director\n2-sort by rank\n");
        scanf("%d", &n);
        if (n == 1) {
            sort_file<film>(pfile, compare_films_by_director);
        } else if (n == 2) {
            sort_file<film>(pfile, compare_films_by_rank);
        } else {
            printf("Choose another option\n");
        }
        fclose(pfile);
    }
    else{
        error_func(FILE_ERROR_KEY);
    }
}

void delete_cinemas_by_artist(){
    FILE *pfile=fopen(FILENAME,"r+b");
    if(pfile!=NULL) {
        char* delete_director;
        printf("Director to delete:\n");
        scanf("%s", delete_director);
        int persons_count = get_records_count_in_file<film>(pfile);
        for (int i = 0; i < persons_count; i++) {
            film current_film = read_record_from_file<film>(pfile, i);
            if (strcmp(delete_director,current_film.director)==0) {
                remove_record_from_file<film>(pfile, i);
                persons_count--;
                i--;
            }
        }
    }
    else{
        error_func(FILE_ERROR_KEY);
    }
}