#include "sum_of_multiples.h"

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, 
                 const unsigned int limit){
     
    // we need the actuall size of the buffer
    int multiples_numbers = 0;
    for (int i = 0; i < (int)number_of_factors; i++){
        if (factors[i] == 0){
            continue;
        }
        for (int j = 1; factors[i]*j < limit; j++){
            multiples_numbers++;
        }
    }

    if (multiples_numbers == 0){
        return 0;
    }
    unsigned int *multiples = malloc(multiples_numbers * sizeof(unsigned int));

    if (multiples == NULL){
        return -1;
    }

    int index = 0;
    for (int i = 0; i < (int)number_of_factors; i++){
        if (factors[i] <= 0){
            continue;
        }
        for (int n = 1; factors[i]*n < limit; n++){
            multiples[index++] = factors[i]*n;
        }
    }
    
    // remove duplicates
    for (int i = 0; i < multiples_numbers; i++){
        for (int j = i + 1; j < multiples_numbers; j++){
            if (multiples[i] == multiples[j]){
                for (int n = j; n < multiples_numbers - 1; n++){
                    multiples[n] = multiples[n + 1];
                }
                multiples_numbers--;
                j--;
            }
        }
    }

    unsigned int result = 0;
    for (int i = 0; i < multiples_numbers; i++){
        result += multiples[i];
    }

    free(multiples);
    return result; 
}