#include "luhn.h"

bool luhn(const char *num){
    int len = 0;
    int result = 0;
    // len is not counting the '\0' terminator.
    // taking the len of the string and cecking if there is an invalid char.
    for (int n = 0; num[n] != '\0'; n++){
        switch (num[n]){
            case '0':
                len++;
                continue;
            case '1':
                len++;
                continue;        
            case '2':
                len++;
                continue;
            case '3':
                len++;
                continue;
            case '4':
                len++;
                continue;
            case '5':
                len++;
                continue;
            case '6':
                len++;
                continue;
            case '7':
                len++;
                continue;
            case '8':
                len++;
                continue;
            case '9':
                len++;
                continue;
            case ' ':
                len++;
                continue;
            default:
                return false;
        }
    }

    // cloning the num array without spaces or scores.
    char digits[len + 1];
    int i = 0;
    for (int n = 0; n < len; n++){
        if (num[n] == ' '){
            continue;
        }
        digits[i] = num[n];
        i++;
    }
    digits[i] = '\0';

    // cecking it the len without space is greater than 1.
    if (i <= 1){
        return false;
    }

    for (int n = i - 2; n >= 0; n -= 2){
        int current_digit = (digits[n] - '0') * 2;
        if (current_digit > 9){
            current_digit -= 9;
        }
        result += current_digit;
        digits[n] = 'x';
    }

    //sum of the remaining digits.
    for (int n = 0; n < i; n++){
        if (digits[n] == 'x'){
            continue;
        }
        result += digits[n] - '0';
    }

    return result % 10 == 0;
}