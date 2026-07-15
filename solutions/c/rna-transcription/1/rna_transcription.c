#include "rna_transcription.h"
#include <string.h>
#include <stdlib.h>

char *to_rna(const char *dna){
    int len = strlen(dna);
    
    char *rna = malloc(len + 1);
    if (!rna){
        return NULL;
    }
    
    for (int j = 0; j < len; j++){
        switch (dna[j]){
            case 'G':
                rna[j] = 'C';
                break;
            case 'C':
                rna[j] = 'G';
                break;
            case 'T':
                rna[j] = 'A';
                break;
            case 'A':
                rna[j] = 'U';
                break;
            default:
                rna[j] = dna[j];
        }
    }
    
    rna[len] = '\0';
    
    return rna;
}