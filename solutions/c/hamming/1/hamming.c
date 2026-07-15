#include "hamming.h"
#include <string.h>

int compute(const char *lhs, const char *rhs){
    if (strlen(lhs) != strlen(rhs)){
        return -1;
    }
    
    int differences = 0;
    
    while (*lhs != '\0'){
        if (*lhs != *rhs){
            differences++;
        }
        lhs++;
        rhs++;
    }
    return differences;
}