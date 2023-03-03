#include <stdio.h>
#include <malloc.h>
#define FORMAT_RIGHT_INPUT (-2)
#define FORMAT_BEGINNING_1 "Enter the number of column of the matrix\n"
#define FORMAT_BEGINNING_2 "Enter the number of elements in line\n"
#define Format_wrongmatrixsize (-3)
#define Format_wrongmatrixsize_output "Wrong size of matrix"
#define Format_wrong_memory (-4)
#define Format_wrong_memory_outut "Wrong memory"
#define Format_mass "matrix[%d][%d]="
#define Format_wrongelem (-5)
#define Format_input_int "%d"
#define Format_input_double "%lf"
#define Format_wrongelem_output "Wrong elem in matrix"
#define Format_output_all " %g"
int scan(int *n){
    if (!scanf(Format_input_int,n)){
        return Format_wrongmatrixsize;
    }
    else{
        return FORMAT_RIGHT_INPUT;
    }
}
void output(int n){
    if(n==Format_wrongmatrixsize){
        printf(Format_wrongmatrixsize_output);
    }
    else if(n==Format_wrong_memory){
        printf(Format_wrong_memory_outut);
    }
    else if(n==Format_wrongelem){
        printf(Format_wrongelem_output);
    }
}
double** mall(int m, int n){
    double** matrix=(double**)malloc(n* sizeof(double*)+m*n* sizeof(double));
    if (matrix!=NULL){
        double *start=(double*)((char*)matrix+n*sizeof(double*));
        for(int i=0;i<n;i++){
            matrix[i]=start+i*m;
        }
    }
    return matrix;
}
int check_matrix(double** matrix){
    if(matrix==NULL){
        return Format_wrong_memory;
    }
    else{
        return FORMAT_RIGHT_INPUT;
    }
}
int inmass(double** matrix,int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf(Format_mass,i,j);
            if(!scanf(Format_input_double,matrix[i]+j)){
                return Format_wrongelem;
            }
        }
    }
    return FORMAT_RIGHT_INPUT;
}
void output_matrix(int n,int m, double** matrix){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf(Format_output_all,matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void swap(double *pa,double *pb){
    double temp=*pa;
    *pa=*pb;
    *pb=temp;
}
double search_max(int n,int m,double** matrix){
    double end_max=matrix[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] > end_max) {
                end_max = matrix[i][j];
            }
        }
    }
    return end_max;
}
double search_min(int n,int m,double** matrix){
    double min=matrix[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    return min;
}
void direction(int *i,int *j,int *beg_i,int *beg_j,int *end_i,int *end_j,int *pred_i,int *pred_j,int n,int m){
    if ((*i == *beg_i) && (*j < m - *end_j - 1)) {
        *pred_j=*j;
        *j += 1;
    } else if ((*j == m - *end_j - 1) && (*i < n - *end_i - 1)) {
        *pred_i=*i;
        *i += 1;
    } else if ((*i == n - *end_i - 1) && (*j > *beg_j)) {
        *pred_j=*j;
        *j -= 1;
    } else {
        *pred_i=*i;
        *i -= 1;
    }
    if ((*i == *beg_i + 1) && (*j == *beg_j) && (*beg_j != m - *end_j - 1)) {
        *beg_i += 1;
        *beg_j += 1;
        *end_i += 1;
        *end_j += 1;
    }
}
void sort_spiral(int n, int m, double **matrix) {
    int i_swap = 0, j_swap = 0;
    int beg_i = 0, beg_j = 0, end_i = 0, end_j = 0, i = 0, j = 0, i_max = 0, j_max = 0;
    double end_max = search_max(n,m,matrix), min = search_min(n,m,matrix), max = matrix[0][0];
    int pred_i=0,pred_j=-1;
    end_max += 1;
    i = 0;
    j = -1;
    for (int z = 0; z < n * m - 1; z++) {
        direction(&i,&j,&beg_i,&beg_j,&end_i,&end_j,&pred_i,&pred_j,n,m);
        for(int new_i = 0; new_i<n; new_i++)
        {
            for(int new_j = 0; new_j<m; new_j++)
            {
                if((matrix[new_i][new_j]>max)&&(matrix[new_i][new_j]<end_max)){
                    i_swap = new_i;
                    max = matrix[new_i][new_j];
                    j_swap = new_j;
                }
                else if(matrix[new_i][new_j]==matrix[pred_i][pred_j]&&((new_i!=pred_i)||(new_j!=pred_j))){
                    j_swap = new_j;
                    i_swap = new_i;
                }
            }
        }
        end_max = matrix[i_swap][j_swap];
        max = min;
        swap(matrix[i_swap] + j_swap, matrix[i] + j);
    }
}
void free1(double **matrix){
    free(matrix);
}
void process(int n,int m,double** matrix){
    output_matrix(n,m,matrix);
    sort_spiral(n,m,matrix);
    output_matrix(n,m,matrix);
    free1(matrix);
}
int main() {
    int m, n, flag_column,flag_line,flag_matrix,flag_elem;
    double** matrix;
    printf((FORMAT_BEGINNING_1));
    flag_column = scan(&n);
    if (flag_column == FORMAT_RIGHT_INPUT) {
        printf((FORMAT_BEGINNING_2));
        flag_line = scan(&m);
        if (flag_line==FORMAT_RIGHT_INPUT){
            matrix=mall(m,n);
            flag_matrix=check_matrix(matrix);
            if (flag_matrix==FORMAT_RIGHT_INPUT){
                flag_elem=inmass(matrix,n,m);
                if(flag_elem==FORMAT_RIGHT_INPUT){
                    process(n,m,matrix);
                }
                else{
                    output(Format_wrongelem);
                }
            }
            else{
                output(Format_wrong_memory);
            }
        }
        else{
            output(Format_wrongmatrixsize);
        }
    }
    else{
        output(Format_wrongmatrixsize);
    }
}
