#include "armstrong_numbers.h"
#include <math.h>

bool is_armstrong_number(int candidate){
    int digits[10];
    int len = 0;
    int copy = candidate;

    while (copy > 0){
        digits[len] = copy % 10;
        copy = copy / 10;
        len++;
    }

    int result = 0;

    for (int i = len - 1; i >= 0; i--){
        result += pow(digits[i], len);
    }

    return candidate == result;
}