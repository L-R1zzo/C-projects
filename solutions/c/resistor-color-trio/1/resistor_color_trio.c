#include "resistor_color_trio.h"
#include <math.h>

resistor_value_t color_code(resistor_band_t colors[3]){
    resistor_value_t result;
    result.value = (colors[0]*10 + colors[1]) * pow(10, colors[2]);

    if (result.value < 1000){
        result.unit = OHMS;
    } else if (result.value < 1000000){
        result.unit = KILOOHMS;
        result.value = result.value / 1000;
    } else if (result.value < 1000000000){
        result.unit = MEGAOHMS;
        result.value = result.value / 1000000;
    } else {
        result.unit = GIGAOHMS;
        result.value = result.value / 1000000000;
    }

    return result;
}