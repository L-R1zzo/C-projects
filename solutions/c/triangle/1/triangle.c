#include "triangle.h"

bool is_equilateral(triangle_t t){
    if (t.a + t.b < t.c){
        return false;
    } else if (t.a + t.c < t.b){
        return false;
    } else if (t.b + t.c < t.a){
        return false;
    } else if (t.a == 0 || t.b == 0 || t.c == 0){
        return false;
    }
    
    if (t.a == t.b && t.b == t.c){
        return true;
    } else {
        return false;
    }
    
}

bool is_isosceles(triangle_t t){
    if (t.a + t.b < t.c){
        return false;
    } else if (t.a + t.c < t.b){
        return false;
    } else if (t.b + t.c < t.a){
        return false;
    }
    
    if (t.a == t.b || t.b == t.c || t.a == t.c){
        return true;
    } else {
        return false;
    }
    
}

bool is_scalene(triangle_t t){
    if (t.a + t.b < t.c){
        return false;
    } else if (t.a + t.c < t.b){
        return false;
    } else if (t.b + t.c < t.a){
        return false;
    }
    
    if (t.a != t.b && t.b != t.c && t.a != t.c){
        return true;
    } else {
        return false;
    }
    
}