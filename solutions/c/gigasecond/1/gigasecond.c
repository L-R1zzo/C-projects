#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size){
    time_t result = input + (time_t)1000000000;
    struct tm *result_tm = gmtime(&result);
    strftime(output, size, "%Y-%m-%d %H:%M:%S", result_tm);
}