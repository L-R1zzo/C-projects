#include "perfect_numbers.h"

kind classify_number(int number){
    if (number <= 0){
        return ERROR;
    }
    if (number == 1){
        return DEFICIENT_NUMBER;
    }
    
    int factors[64] = {1};
    int index = 1;
    
    for (long int factor = 2; factor != number; factor++){
        if (number % factor == 0){
            factors[index] = factor;
            index++;
        }
    }

    int factors_sum = 0;
    
    while (index >= 0){
        factors_sum += factors[index];
        index--;
    }

    if (factors_sum > number){
        return ABUNDANT_NUMBER;
    } else if (factors_sum < number){
        return DEFICIENT_NUMBER;
    } else {
        return PERFECT_NUMBER;
    }
    
}