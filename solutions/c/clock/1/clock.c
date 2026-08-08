#include "clock.h"

clock_t clock_create(int hour, int min){
    clock_t clock;
    while (min >= 60){
        min -= 60;
        hour++;
    }

    while (min < 0){
        min += 60;
        hour--;
    }
    
    while (hour >= 24){
        hour -= 24;
    }

    while (hour < 0){
        hour += 24;
    }
    
    snprintf(clock.text, sizeof(clock.text), "%02d:%02d", hour, min);
    return clock;
}

void split_timer(clock_t clock, char *string_hour, char *string_min){
    bool control = false;
    int index = 0;
    for (int n = 0; clock.text[n] != '\0'; n++){
        if (clock.text[n] == ':'){
            control = true;
            string_hour[n] = '\0';
            continue;
        }
        if (!control){
            string_hour[n] = clock.text[n];
            continue;
        }
        string_min[index++] = clock.text[n];
    }
    string_min[index] = '\0';
}

clock_t clock_add(clock_t clock, int min){
    char string_hour[4];
    char string_min[4];
    split_timer(clock, string_hour, string_min);

    int new_hour = strtol(string_hour, NULL, 10);
    int new_min = strtol(string_min, NULL, 10) + min;

    clock_t new_clock = clock_create(new_hour, new_min);
    return new_clock;
}

clock_t clock_subtract(clock_t clock, int minute_subtract){
    char string_hour[4];
    char string_min[4];
    split_timer(clock, string_hour, string_min);
    
    int new_hour = strtol(string_hour, NULL, 10);
    int new_min = strtol(string_min, NULL, 10) - minute_subtract;

    clock_t new_clock = clock_create(new_hour, new_min);
    return new_clock;
}

bool clock_is_equal(clock_t a, clock_t b){
    for (int n = 0; a.text[n] != '\0'; n++){
        if (a.text[n] != b.text[n]){
            return false;
        }
    }
    return true;
}