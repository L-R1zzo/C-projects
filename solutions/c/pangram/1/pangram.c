#include "pangram.h"
#include <ctype.h>
#include <stddef.h>

bool is_pangram(const char *sentence){
    if (sentence == NULL){
        return false;
    }
    char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
    int sentence_len = 1;
    for (int i = 0; sentence[i] != '\0'; i++){
        sentence_len++;
    }

    bool finded = true;
    for (int i = 0; i < 26; i++){
        if (finded == false){
            return false;
        }
        for (int j = 0; j < sentence_len; j++){
            if (alphabet[i] != tolower(sentence[j])){
                finded = false;
                continue;
            } else {
                finded = true;
                break;
            }
        }
    }
    return true;
}