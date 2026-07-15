#include "darts.h"
#include <math.h>

typedef enum {
    OUT = 0,
    OUTER = 1,
    MIDDLE = 5,
    INNER = 10
} points_t;


uint8_t score(coordinate_t landing){
    float distance = sqrtf(landing.x * landing.x + landing.y * landing.y);
    
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