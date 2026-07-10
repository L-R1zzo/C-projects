#include <string.h>
#include <stdio.h>

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

int main(void){
    char dna1[32];
    char dna2[32];

    printf("Write a DNA strand (example: GAGCCTACTAACGGGAT): ");
    scanf("%s", dna1);
    printf("Write a second DNA strand (example: GAGCCTACTAACGGGAT): ");
    scanf("%s", dna2);

    printf("The hamming distance between the DNA strands is: %d\n", compute(dna1,dna2));
    
    return 0;
}