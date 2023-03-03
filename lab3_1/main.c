#include <stdio.h>
#include <math.h>
#define FORMAT_BEGINNING1 "Hello there, enter your epselen\n"
#define FORMAT_BEGINNING2 "Enter a and b\n"
#define FORMAT_INPUT "%lf"
#define FORMAT_WRONG_PARAMETRS "Parametrs are wrong\n"
#define FORMAT_WRONG_PARAMETRS0 0
#define FORMAT_EQUAL_PARAMETRS 19
#define FORMAT_RIGHT_PARAMETRS 1
#define FORMAT_AB 20
void scan(double *x){
    scanf("%lf",x);
}
void output(double x){
    if(x==FORMAT_WRONG_PARAMETRS0){
        printf(FORMAT_WRONG_PARAMETRS);
    }
    else if (x==FORMAT_EQUAL_PARAMETRS){
        printf("0");
    }
    else{
        printf(FORMAT_INPUT,x);
    }
}

double f(double x){
    return log(x);
}

double funcintegral(double N,double a,double b){
    double s1=0;
    double s2=0;
    double h=(b-a)/(2*N);
    for (int i=0; i<2*N;i+=2){
        s1+=f(a+i*h);
        s2+=f(a+(i+1)*h);
    }
    return ((h/3)*(f(a)+4*s1+2*s2+f(2*N)-2*f(a+2*N*h)));
}
double funcwork(double epselen,double a,double b){
    double integ1=0, integ2=-5;
    double N=1;
    while(fabs(integ1-integ2)>epselen){
        N=N*2;
        integ2=integ1;
        integ1=funcintegral(N,a,b);
    }
    return integ1;
}

int obrabotka(double epselen,double a,double b){
    if (a<=0 || b<=0 || epselen<=0){
        return FORMAT_WRONG_PARAMETRS0;
    }
    else if(a==b){
        return FORMAT_EQUAL_PARAMETRS;
    }
    else if(a>b){
        return FORMAT_AB;
    }
    else{
        return FORMAT_RIGHT_PARAMETRS;
    }
}

int main() {
    double epselen,a,b,integ1;
    int flag;
    printf(FORMAT_BEGINNING1);
    scan(&epselen);
    printf(FORMAT_BEGINNING2);
    scan(&a);
    scan(&b);
    flag=obrabotka(epselen,a,b);
    if(flag==FORMAT_RIGHT_PARAMETRS){
        integ1=funcwork(epselen,a,b);
        output(integ1);
    }
    else if(flag==FORMAT_AB){
        integ1=funcwork(epselen,b,a);
        output(integ1*(-1));
    }
    else if(flag==FORMAT_WRONG_PARAMETRS0){
        output(FORMAT_WRONG_PARAMETRS0);
    }
    else{
        output(FORMAT_EQUAL_PARAMETRS);
    }
    return 0;
}