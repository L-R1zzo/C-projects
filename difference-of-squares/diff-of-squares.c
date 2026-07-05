#include <stdio.h>

unsigned int square_of_sum(unsigned int n){
    unsigned int sum = 0; 
        for (unsigned int i = 1; i <= n; i++){
            sum += i;
        }
    unsigned int square = sum*sum;
    return square;
}

unsigned int sum_of_squares(unsigned int n){
    unsigned int sum = 0;
    for (unsigned int i = 1; i <= n; i++){
        sum += (i*i);
    }
    return sum;
}

unsigned int difference_of_squares(unsigned int n){
    return square_of_sum(n) - sum_of_squares(n);
}

int main(){
    unsigned int number;
    printf("Choose a an integer that is greater or equal to zero: ");
    scanf("%u", &number);
    printf("\n");
    printf("The square of the sum of the natural numbers less or greater than ");
    printf("%u", number);
    printf(" is: ");
    printf("%u", square_of_sum(number));
    printf("\n");
    printf("The sum of the squares of the natural numbers less or greater than ");
    printf("%u", number);
    printf(" is: ");
    printf("%u", sum_of_squares(number));
    printf("\n");
    printf("The difference beetwen the square of sum and the sum of squares is: ");
    printf("%u", difference_of_squares(number));
    printf("\n");
    
    return 0;
}