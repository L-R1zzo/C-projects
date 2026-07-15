#include "leap.h"
#include <stdio.h>
#include <stdbool.h>
bool leap_year(int year){
    if (year % 4 != 0){
        printf("%d was not a leap year as it's not divisible by 4.\n", year);
        return false;
    } else if (year % 100 == 0 && year % 400 != 0){
        printf("%d was not a leap year as it's not divisible by 400.\n", year);
        return false;
    } else {
        printf("%d was a leap year!", year);
        return true;
    }
}