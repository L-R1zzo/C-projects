#include "high_scores.h"

int32_t latest(const int32_t *scores, size_t scores_len){
    return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len){
    int32_t selected = scores[0]; 
    for (size_t i = 1; i < scores_len; i++){
        if (selected < scores[i]){
            selected = scores[i];
        }
    }
    return selected;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output){
    size_t copy_len = scores_len;
    size_t counter = 0;
    int32_t copy[scores_len];
    for (size_t i = 0; i < scores_len; i++){
        copy[i] = scores[i];
    }
    
    if (scores_len <= (size_t)3){
        while (counter < copy_len){
            int32_t max = copy[0];
            size_t max_index = 0;
            for (size_t i = 1; i < scores_len; i++){
                if (max < copy[i]){
                    max = copy[i];
                    max_index = i;
                }
            }
            output[counter] = max;

            for (size_t k = max_index; k < scores_len - 1; k++){
                copy[k] = copy[k + 1];
            }
            scores_len--;
            counter++;
        }
        return counter;
    }
    

    while (counter < (size_t)3){
        int32_t max = copy[0];
        size_t max_index = 0;
        for (size_t i = 1; i < scores_len; i++){
            if (max < copy[i]){
                max = copy[i];
                max_index = i;
            }
        }
        output[counter] = max;

        for (size_t k = max_index; k < scores_len - 1; k++){
            copy[k] = copy[k + 1];
        }
        scores_len--;
        counter++;
    }
    return counter;
}



