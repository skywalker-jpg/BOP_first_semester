#include <stdio.h>
#define FORMAT_BEGINNING "Hello there!\nPlease enter your epselen"
#define FORMAT_WRONG_EPSELEN "Wrong epselen"
#define FORMAT_INPUT "%lf"
#define FORMAT_WRONG_EPSELEN1 0
#define FORMAT_RIGHT_PARAMETRS 1
void scan(double *x){
    scanf(FORMAT_INPUT,x);
}
void output(double x){
    if(x==FORMAT_WRONG_EPSELEN1){
        printf(FORMAT_WRONG_EPSELEN);
    }
    else{
        printf(FORMAT_INPUT,x);
    }
}

double funcsum(double epselen){
    double factor=1;
    double counter=1;
    double prevsum=0;
    double sum1=1;
    while (sum1-prevsum>epselen){
        counter=counter+1;
        factor=factor*counter;
        prevsum=sum1;
        sum1=sum1+1/factor;
    }
    return sum1;

}

double obrabotka(double epselen){
    if (epselen>=1 || epselen<=0){
        return FORMAT_WRONG_EPSELEN1;
    }
    else{
        return FORMAT_RIGHT_PARAMETRS;
    }
}

int main() {
    double flag1,epselen;
    printf(FORMAT_BEGINNING);
    scan(&epselen);
    flag1=obrabotka(epselen);
    if(flag1==FORMAT_RIGHT_PARAMETRS){
        flag1=funcsum(epselen);
        output(flag1);
    }
    else{
        output(FORMAT_WRONG_EPSELEN1);
    }
}
