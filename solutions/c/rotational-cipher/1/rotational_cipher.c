#include "rotational_cipher.h"


char *rotate(const char *text, int shift_key){
    char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
    char capital_alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int shift = 0;
    char *rotated = malloc(strlen(text)+1);
    for (size_t n = 0; n < strlen(text); n++){
        for (size_t i = 0; i < strlen(alphabet); i++){
            if (text[n] == alphabet[i]){
                shift = (int)i + shift_key;
                if (shift > 25){
                    shift -= 26;
                }
                rotated[n] = alphabet[shift];
                break;
            } else {
                if (text[n] == capital_alphabet[i]){
                    shift = (int)i + shift_key;
                    if (shift > 25){
                        shift -= 26;
                    }
                    rotated[n] = capital_alphabet[shift];
                    break;
                } else {
                    if ((int)i == 25){
                        rotated[n] = text[n];
                    }
                }
            }
        }
    }
    rotated[strlen(text)] = '\0';
    return rotated;
}