#include "stdio.h"
#define eq1 (2*x+2)
#define eq2 (0.5*x-1)
#define eq3 (-x+2)
#define sec1 1
#define sec2 2
#define sec3 3
#define sec4 4
#define sec5 5
#define sec6 6
#define sec7 7
#define sec11 11
#define sec22 22
#define sec33 33
#define sec12 12
#define sec23 23
#define sec13 13
#define sec1_output "point is in section number 1 \n"
#define sec2_output "point is in section number 2 \n"
#define sec3_output "point is in section number 3 \n"
#define sec4_output "point is in section number 4 \n"
#define sec5_output "point is in section number 5 \n"
#define sec6_output "point is in section number 6 \n"
#define sec7_output "point is in section number 7 \n"
#define line1_output "point is in line 1 \n"
#define line2_output "point is in line 2 \n"
#define line3_output "point is in line 3 \n"
#define line13_output "point is in lines 1 and 3 \n"
#define line23_output "point is in line 2 and 3 \n"
#define line12_output "point is in line 3 and 1 \n"

float input1(){
    float x;
    while (scanf("%f", &x) != 1)
    {
        printf("Error input");
        scanf("%*s");
    }
    return x;
}
int obrabotka(float x, float y){
    if (y==eq1 && y!=eq2 && y!=eq3){
        return sec11;
    }
    else if (y!=eq1 && y==eq2 && y!=eq3){
        return sec22;
    }
    else if (y!=eq1 && y!=eq2 && y==eq3){
        return sec33;
    }
    else if (y==eq1 && y==eq2 && y!=eq3){
        return sec12;
    }
    else if (y!=eq1 && y==eq2 && y==eq3){
        return sec23;
    }
    else if (y==eq1 && y!=eq2 && y==eq3){
        return sec13;
    }
    else if (y<eq1 && y>eq2 && y>eq3){
        return sec1;
    }
    else if (y!=eq1 && y<eq2 && y>eq3){
        return sec2;
    }
    else if (y<eq1 && y<eq2 && y<eq3){
        return sec3;
    }
    else if (y>eq1 && y<eq2 && y!=eq3){
        return sec4;
    }
    else if (y>eq1 && y>eq2 && y<eq3){
        return sec5;
    }
    else if (y>eq1 && y!=eq2 && y>eq3){
        return sec6;
    }
    else if (y<eq1 && y>eq2 && y<eq3){
        return sec7;
    }
    return 0;
}
void output(int loc){
    if (loc==sec11){
        printf(line1_output);
    }
    else if (loc==sec22){
        printf(line2_output);
    }
    else if (loc==sec33){
        printf(line3_output);
    }
    else if (loc==sec12){
        printf(line12_output);
    }
    else if (loc==sec23){
        printf(line23_output);
    }
    else if (loc==sec13){
        printf(line13_output);
    }
    else if (loc==sec1){
        printf(sec1_output);
    }
    else if (loc==sec2){
        printf(sec2_output);
    }
    else if (loc==sec3){
        printf(sec3_output);
    }
    else if (loc==sec4){
        printf(sec4_output);
    }
    else if (loc==sec5){
        printf(sec5_output);
    }
    else if (loc==sec6){
        printf(sec6_output);
    }
    else if (loc==sec7){
        printf(sec7_output);
    }
}
int main() {
    printf("Task 2 \n");
    printf("Line equations\n: y=2x+2 (1)\n y=0.5*x-1 (2)\n y=-x+2 (3)\n");
    printf("Coordinates: \n");
    float x=input1();
    float y=input1();
    int loc=obrabotka(x,y);
    output(loc);
}