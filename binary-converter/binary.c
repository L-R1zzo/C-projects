#include <stdio.h>
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
                return -1;
        }
    }
    return result;
}

int main(void){
    char selected_number[33];
    printf("Enter a binary number: ");
    scanf("%s", selected_number);
    printf("The number converted in decimal system is: %d\n", convert(selected_number));
    
    return 0;
}
