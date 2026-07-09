#include <stdio.h>
#include <stdint.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} coordinate_t;

typedef enum {
    OUT = 0,
    OUTER = 1,
    MIDDLE = 5,
    INNER = 10
} points_t;


uint8_t score(coordinate_t landing){
    float distance = sqrt(landing.x * landing.x + landing.y * landing.y);
    
    if (distance <= 10){
        if (distance <= 5){
            if (distance <= 1){
                return INNER;
            } else {
                return MIDDLE;
            }
        } else {
            return OUTER;
        }
    } else {
        return OUT;
    }
}

int main(void){
    coordinate_t dart;
    printf("Points: OUT - 0, OUTER CIRCLE - 1, MIDDLE CIRCLE - 5, INNER CIRCLE - 10\n");
    printf("Enter the x - y coordinates of the position of the dart: ");
    scanf("%f %f", &dart.x, &dart.y);
    printf("You scored: %hhu points\n", score(dart));


    return 0;
}