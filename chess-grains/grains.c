#include <stdint.h>
#include <stdio.h>

uint64_t square(uint8_t n){
    if (n >= 1 && n <= 64){
        return 1ULL << (n-1);
    }
    return 0;
}

uint64_t total(){
    uint64_t total = 0;
    for (int i = 1; i <= 64; i++){
         total += 1ULL << (i-1);       
    }
    return total;
}

int main(){
    uint8_t number;
    printf("Choose a number of a square: ");
    scanf("%hhu", &number);
    printf("\n");
    printf("The numbers of wheat grains on the ");
    printf("%hhu", number);
    printf("th is: ");
    printf("%lu", square(number));
    printf("\n");
    printf("The numbers of wheat grains on the chessboard is: ");
    printf("%lu", total());
    printf("\n");
    
    return 0;
}