#include <stdio.h>
#include <malloc.h>
#define FORMAT_BEGINNING "Hello there, enter the size of the matrix \n"
#define FORMAT_INPUT_FOR_INT "%d"
#define FORMAT_OUTPUT_MASS "mass[%d][%d]="
#define FORMAT_INPUT_FOR_DOUBLE "%lf"
#define FORMAT_OUTPUT_FOR_ALL "%g "
#define FORMAT_WRONG_DATA (-1)
#define FORMAT_RIGHT_DATA 1
#define FORMAT_WRONG_DATA_OUTPUT "WRONG DATA"
#define FORMAT_WRONG_SIZE_OF_MASS_OUTPUT "WRONG SIZE OF MASS"
#define FORMAT_WRONG_SIZE_OF_MASS (-2)
#define FORMAT_WRONG_MASS_ELEMENT (-3)
#define FORMAT_WRONG_MASS_ELEMENT_OUTPUT "WRONG ELEMENT IN MASS"
#define FORMAT_OUTPUT_FOR_ANSWER "\nYour mass is:\n"

void outputError(double i){
    if(i==FORMAT_WRONG_DATA){
        printf(FORMAT_WRONG_DATA_OUTPUT);
    }
    else if(i==FORMAT_WRONG_SIZE_OF_MASS){
        printf(FORMAT_WRONG_SIZE_OF_MASS_OUTPUT);
    }
    else if(i==FORMAT_WRONG_MASS_ELEMENT){
        printf(FORMAT_WRONG_MASS_ELEMENT_OUTPUT);
    }
}

int scan(int *n){
    if(!scanf(FORMAT_INPUT_FOR_INT,n)){
        return FORMAT_WRONG_SIZE_OF_MASS;
    }
    else{
        return FORMAT_RIGHT_DATA;
    }
}

double** mall(int n){
    double** mass=(double**) malloc(n*sizeof(double*)+n*n* sizeof(double));
    if(mass!=NULL){
        double* start=(double*)((char*)mass+n*sizeof(double*));
        for(int i=0;i<n;i++){
            mass[i]=start+i*n;
        }
    }
    return mass;
}

int check_mass(double **mass){
    if (mass == NULL) {
        return FORMAT_WRONG_DATA;
    }
    else{
        return FORMAT_RIGHT_DATA;
    }
}

int inmass(double **mass,int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(FORMAT_OUTPUT_MASS, i, j);
            if (!scanf(FORMAT_INPUT_FOR_DOUBLE, mass[i]+j)) {
                return FORMAT_WRONG_MASS_ELEMENT;
            }
        }
    }
    return(FORMAT_RIGHT_DATA);
}

void swap(double *pa, double* pb){
    double temp=*pa;
    *pa=*pb;
    *pb=temp;
}


void transpon(double **mass,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            swap((mass[i]+j), (mass[n-1-j]+n-1-i));
        }
    }
}

void output_mass(double **mass,int n){
    printf(FORMAT_OUTPUT_FOR_ANSWER);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf(FORMAT_OUTPUT_FOR_ALL,mass[i][j]);
        }
        printf("\n");
    }
}

void free_memory(double **mass){

    free(mass);
}

int main() {
    int n,flagscan_for_line,flagcheck_mass,flagcheck_elem;
    printf(FORMAT_BEGINNING);
    flagscan_for_line=scan(&n);
    if(flagscan_for_line==FORMAT_RIGHT_DATA){
        double **mass;
        mass=mall(n);
        flagcheck_mass=check_mass(mass);
        if(flagcheck_mass==FORMAT_RIGHT_DATA){
            flagcheck_elem=inmass(mass,n);
            if(flagcheck_elem==FORMAT_RIGHT_DATA){
                transpon(mass,n);
                output_mass(mass,n);
            }
            else{
                outputError(FORMAT_WRONG_MASS_ELEMENT);
            }
        }
        else{
            outputError(FORMAT_WRONG_DATA);
        }
        free_memory(mass);
    }
    else{
        outputError(FORMAT_WRONG_SIZE_OF_MASS);
    }
    return 0;
}
