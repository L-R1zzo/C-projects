#include "isogram.h"
#include <stddef.h>
#include <ctype.h>

bool is_isogram(const char phrase[]){
    if (phrase == NULL){
        return false;
    }
    
    int len = 0;
    
    for (int i = 0; phrase[i] != '\0'; i++){
        len++;
    }

    for (int i = 0; i <= len; i++){
        for (int n = 0; n <= len; n++){
            if (tolower(phrase[i]) == tolower(phrase[n]) && i != n){
                switch (phrase[i]){
                    case 'a':
                        return false;
                    case 'b':
                        return false;
                    case 'c':
                        return false;
                    case 'd':
                        return false;
                    case 'e':
                        return false;
                    case 'f':
                        return false;
                    case 'g':
                        return false;
                    case 'h':
                        return false;
                    case 'i':
                        return false;
                    case 'j':
                        return false;
                    case 'k':
                        return false;
                    case 'l':
                        return false;
                    case 'm':
                        return false;
                    case 'n':
                        return false;
                    case 'o':
                        return false;
                    case 'p':
                        return false;
                    case 'q':
                        return false;
                    case 'r':
                        return false;
                    case 's':
                        return false;
                    case 't':
                        return false;
                    case 'u':
                        return false;
                    case 'v':
                        return false;
                    case 'w':
                        return false;
                    case 'x':
                        return false;
                    case 'y':
                        return false;
                    case 'z':
                        return false;
                    default:
                        continue;
                        break;
                }
            } else {
                continue;
            }
        }
    }

    return true;
}