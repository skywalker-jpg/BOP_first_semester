
#ifndef LASTONE_TEMPLATE_FUNCS_H
#define LASTONE_TEMPLATE_FUNCS_H
#include "file_funcs.h"
#include "io.h"

template <typename T>
int get_records_count_in_file(FILE *pfile)
{
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return (size / sizeof(T));
}

template <typename T>
T read_record_from_file(FILE *pfile, int index)
{
    int offset = index * sizeof(T);
    fseek(pfile, offset, SEEK_SET);
    T readed_record;
    fread(&readed_record, sizeof(T), 1, pfile);
    rewind(pfile);
    return readed_record;
}

template <typename T>
void write_record_in_file(FILE *pfile, const T *record_to_write, int index)
{
    int offset = index * sizeof(T);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(T), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

template <typename T>
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2)
{
    T record1 = read_record_from_file<T>(pfile, record_index1);
    T record2 = read_record_from_file<T>(pfile, record_index2);

    write_record_in_file<T>(pfile, &record1, record_index2);
    write_record_in_file<T>(pfile, &record2, record_index1);
}

template <typename T>
int find_extremum_index_in_file(FILE *pfile,
    int total_records_count,
    int start_index,
    int (*compare_records)(const T *record1, const T *record2))
{
    int extremum_index = start_index;
    T extremum_record = read_record_from_file<T>(pfile, extremum_index);

    for (int i = start_index + 1; i < total_records_count; i++)
    {
        T current_record = read_record_from_file<T>(pfile, i);
        if (compare_records(&current_record, &extremum_record))
        {
            extremum_index = i;
            extremum_record = current_record;
        }
    }

    return extremum_index;
}

template <typename T>
void sort_file(FILE *pfile, int (*compare_records)(const T *record1, const T *record2))
{
    int records_count = get_records_count_in_file<film>(pfile);
    for (int i = 0; i < records_count; i++)
    {
        int extremum_index = find_extremum_index_in_file(pfile, records_count, i, compare_records);
        swap_records_in_file<film>(pfile, i, extremum_index);
    }
}

template <typename T>
void remove_record_from_file(FILE *pfile, int record_index)
{
    int records_count = get_records_count_in_file<film>(pfile);
    for (int i = record_index + 1; i < records_count; i++)
    {
        T current_record = read_record_from_file<T>(pfile, i);
        write_record_in_file<T>(pfile, &current_record, i - 1);
    }
    int new_file_size = (records_count - 1) * sizeof(T);
    int file_descriptor = fileno(pfile);
    chsize(file_descriptor, new_file_size);
}
#endif
