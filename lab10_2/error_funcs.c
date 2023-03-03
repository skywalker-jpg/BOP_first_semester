#include "error_funcs.h"
#include "stdio.h"
void error(int n){
    if(n==Memory_allocation_error_key)
        printf(Memory_allocation_error);
    else if(n==number_of_students_error_key)
        printf(number_of_students_error);
    else if(n==mark_error_key)
        printf(mark_error);
}
