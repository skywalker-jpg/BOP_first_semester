#ifndef LAB10_1_STRUCTURE_H
#define LAB10_1_STRUCTURE_H
#define MAX_WORD_LEN 80
#define MARKS_COUNT 5
typedef struct Student_tag {
    char surname[MAX_WORD_LEN];
    int marks[MARKS_COUNT];
    int min_mark;
    double avg_score;
}student;


#endif
