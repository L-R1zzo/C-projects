#include "square_root.h"

int square_root(int number){
    int low = 0;
    int high = number;

    while (high >= low){
        int mid = (high + low) / 2;

        if (mid*mid == number){
            return mid;
        } else if (mid*mid > number){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
    
}