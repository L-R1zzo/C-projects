#include <stdio.h>


void leap_year(int year){
    if (year % 4 != 0){
        printf("%d was not a leap year as it's not divisible by 4.\n", year);
    } else if (year % 100 == 0 && year % 400 != 0){
        printf("%d was not a leap year as it's not divisible by 400.\n", year);
    } else {
        printf("%d was a leap year!\n", year);
    }
}

int main(){
    int year = 0;
    printf("Select a year: ");
    scanf("%d", &year);
    leap_year(year);
    
    return 0;
}




