#include <stdio.h>
#include <malloc.h>
#define FORMAT_BEGINNING "Hello there, enter the size of the mass \n"
#define FORMAT_INPUT_FOR_INT "%d"
#define FORMAT_OUTPUT_MASS "mass[%d]="
#define FORMAT_INPUT_FOR_DOUBLE "%lf"
#define FORMAT_WRONG_DATA (-1)
#define FORMAT_RIGHT_DATA 1
#define FORMAT_WRONG_DATA_OUTPUT "WRONG DATA"
#define FORMAT_WRONG_SIZE_OF_MASS_OUTPUT "WRONG SIZE OF MASS"
#define FORMAT_WRONG_SIZE_OF_MASS1 (-2)
#define FORMAT_WRONG_MASS_ELEMENT (-3)
#define FORMAT_WRONG_MASS_ELEMENT1 "WRONG ELEMENT IN MASS"
#define FORMAT_OUTPUT_FOR_MASS "mass[%d]=%lf \n"
#define FORMAT_OUTPUT_FOR_ANSWER "\n Your mass is:\n"

void free1(double *mass){
    free(mass);
}

void outputError(double sum){
    if(sum==FORMAT_WRONG_DATA){
        printf(FORMAT_WRONG_DATA_OUTPUT);
    }
    else if(sum==FORMAT_WRONG_SIZE_OF_MASS1){
        printf(FORMAT_WRONG_SIZE_OF_MASS_OUTPUT);
    }
    else if(sum==FORMAT_WRONG_MASS_ELEMENT){
        printf(FORMAT_WRONG_MASS_ELEMENT1);
    }
}

int scan(int *n){
    if(!scanf(FORMAT_INPUT_FOR_INT,n)){
        return FORMAT_WRONG_SIZE_OF_MASS1;
    }
    else{
        return FORMAT_RIGHT_DATA;
    }
}

int inmass(int n,double *mass) {
    for (int i = 0; i < n; i++){
        printf(FORMAT_OUTPUT_MASS, i);
        if(!scanf(FORMAT_INPUT_FOR_DOUBLE, &mass[i])){
            return FORMAT_WRONG_MASS_ELEMENT;
        }
    }
    return FORMAT_RIGHT_DATA;
}
double checkmass(double *mass){
    if (mass == NULL) {
        return FORMAT_WRONG_SIZE_OF_MASS1;
    }
    else{
        return FORMAT_RIGHT_DATA;
    }
}
void mall(double **mass,int n){
    *mass = (double *) malloc(n * sizeof(double));
}

void swap(double *pa, double* pb){
    double temp=*pa;
    *pa=*pb;
    *pb=temp;
}

int sortpositive(int n, double *mass){
    int j=0;
    for(int i=0;i<n;i++){
        if(mass[i]>0){
            swap(mass+i,mass+j);
            j++;
        }
    }
    return j;
}
void sortToMin(int lastpositive, double *mass){
    for(int i=0; i<lastpositive-1;i++){
        for(int j=0; j<lastpositive-1;j++){
            if(mass[j]<mass[j+1]){
                swap(mass+j,mass+j+1);
            }
        }
    }
}
void sortToMax(int firstnegative,int n, double *mass){
    for(int i=firstnegative;i<n-1;i++){
        for(int j=firstnegative;j<n-1;j++){
            if(mass[j]>mass[j+1]){
                swap(mass+j,mass+j+1);
            }
        }
    }
}

int sortnull(int n,int lastpositive,double *mass){
    int j=lastpositive;
    for(int i=lastpositive; i<n;i++){
        if(mass[i]==0){
            swap(mass+i,mass+j);
            j++;
        }
    }
    return j;
}

void elemsort(int n,double *mass){
    int lastpositive,firstnegative;
    lastpositive=sortpositive(n,mass);
    firstnegative=sortnull(n,lastpositive,mass);
    sortToMin(lastpositive,mass);
    sortToMax(firstnegative,n,mass);
}

void output_mass(double *mass,int n){
    printf(FORMAT_OUTPUT_FOR_ANSWER);
    for(int i=0;i<n;i++){
        printf(FORMAT_OUTPUT_FOR_MASS,i,mass[i]);
    }
}

int main() {
    double *mass;
    int n, flagscan, flagcheckmass, flaginmass;
    printf(FORMAT_BEGINNING);
    flagscan = scan(&n);
    if (flagscan == FORMAT_RIGHT_DATA) {
        mall(&mass,n);
        flagcheckmass = checkmass(mass);
        if (flagcheckmass == FORMAT_RIGHT_DATA) {
            flaginmass = inmass(n, mass);
            if (flaginmass == FORMAT_RIGHT_DATA) {
                elemsort(n,mass);
                output_mass(mass,n);
            }
            else {
                outputError(FORMAT_WRONG_MASS_ELEMENT);
            }
        }
        else {
            outputError(FORMAT_WRONG_SIZE_OF_MASS1);
        }
    }
    else {
        outputError(FORMAT_WRONG_DATA);
    }
    free1(mass);
}
