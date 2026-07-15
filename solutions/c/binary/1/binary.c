#include "binary.h"
#include <string.h>
int convert(const char *input){
    int result = 0;
    int n = strlen(input) - 1;
    int k = strlen(input);
    for (int i = 0; i < k; i++){ 
        switch (input[i]){
            case '0':
                n--;
                break;
            case '1':
                result += 1 << n;
                n--;
                break;
            default:
                return INVALID;
        }
    }
    return result;
}