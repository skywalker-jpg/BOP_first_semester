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
#define FORMAT_OUTPUT "Your answer is: %lf"
void free1(double *mass){
    free(mass);
}
int scan(int *n){
    if(!scanf(FORMAT_INPUT_FOR_INT,n)){
        return FORMAT_WRONG_SIZE_OF_MASS1;
    }
    else{
        return FORMAT_RIGHT_DATA;
    }
}
void output(double sum){
    if(sum==FORMAT_WRONG_DATA){
        printf(FORMAT_WRONG_DATA_OUTPUT);
    }
    else if(sum==FORMAT_WRONG_SIZE_OF_MASS1){
        printf(FORMAT_WRONG_SIZE_OF_MASS_OUTPUT);
    }
    else if(sum==FORMAT_WRONG_MASS_ELEMENT){
        printf(FORMAT_WRONG_MASS_ELEMENT1);
    }
    else{
        printf(FORMAT_OUTPUT,sum);
    }
}
int funcprocess(double *mass, int position, double middle, int n){
    double sum=0;
    for(int i=position; i<n; i++){
        if(mass[i]>middle){
            sum+=mass[i];
        }
    }
    return sum;
}
double funcmiddle(double *mass,int n){
    double max1=mass[0];
    double min1=mass[0];
    double middle;
    for(int i=0; i<n; i++){
        if(mass[i]<min1){
            min1=mass[i];
        }
        if(mass[i]>max1){
            max1=mass[i];
        }
    }
    middle=(max1+min1)/2;
    return middle;
}
int funcposition(double *mass,int n){
    int max1=mass[0];
    int position=0;
    for(int i=0; i<n; i++){
        if(mass[i]>max1){
            max1=mass[i];
            position=i;
        }
    }
    return position;
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
int main() {
    int n, position, flagscan, flagcheckmass, flaginmass;
    double *mass, middle,sum;
    printf(FORMAT_BEGINNING);
    flagscan = scan(&n);
    if (flagscan == FORMAT_RIGHT_DATA) {
        mall(&mass,n);
        flagcheckmass = checkmass(mass);
        if (flagcheckmass == FORMAT_RIGHT_DATA) {
            flaginmass = inmass(n, mass);
            if (flaginmass == FORMAT_RIGHT_DATA) {
                middle = funcmiddle(mass, n);
                position = funcposition(mass, n);
                sum = funcprocess(mass, position, middle, n);
                output(sum);
            }
            else {
                output(FORMAT_WRONG_MASS_ELEMENT);
            }
        }
        else {
            output(FORMAT_WRONG_SIZE_OF_MASS1);
        }
    }
    else {
        output(FORMAT_WRONG_DATA);
    }
    free1(mass);
}