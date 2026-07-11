#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>

typedef enum planet {
   MERCURY,
   VENUS,
   EARTH,
   MARS,
   JUPITER,
   SATURN,
   URANUS,
   NEPTUNE,
} planet_t;

float age(planet_t planet, int64_t seconds){
    switch (planet){
        case MERCURY:
            return seconds / (31557600 * 0.2408467);
        case VENUS:
            return seconds / (31557600 * 0.61519726);
        case EARTH:
            return seconds / 31557600;
        case MARS:
            return seconds / (31557600 * 1.8808158);
        case JUPITER:
            return seconds / (31557600 * 11.862615);
        case SATURN:
            return seconds / (31557600 * 29.447498);
        case URANUS:
            return seconds / (31557600 * 84.016846);
        case NEPTUNE:
            return seconds / (31557600 * 164.79132);
        default:
            return -1;
    }
}

int main(void){
    char planet[20];
    planet_t Enum_planet;
    int64_t seconds;
    printf("Enter a planet that is in our solar system: ");
    scanf("%19s", &planet);

    if (planet[0] != '\0'){
        planet[0] = toupper((unsigned char)planet[0]); 
    }

    for (int i = 1; planet[i] != '\0'; i++){
        planet[i] = tolower((unsigned char)planet[i]);
    }

    if (strcmp(planet, "Mercury") == 0){
        Enum_planet = MERCURY;
    } else if (strcmp(planet, "Venus") == 0){
        Enum_planet = VENUS;
    } else if (strcmp(planet, "Earth") == 0){
        Enum_planet = EARTH;
    } else if (strcmp(planet, "Mars") == 0){
        Enum_planet = MARS;
    } else if (strcmp(planet, "Jupiter") == 0){
        Enum_planet = JUPITER;
    } else if (strcmp(planet, "Saturn") == 0){
        Enum_planet = SATURN;
    } else if (strcmp(planet, "Uranus") == 0){
        Enum_planet = URANUS;
    } else if (strcmp(planet, "Neptune") == 0){
        Enum_planet = NEPTUNE;
    } else {
        return -1;
    }

    printf("Enter the time that you spent living on the planet in seconds: ");
    scanf("%lld", &seconds);
    printf("Your age on %s is %.2f years.\n", planet, age(Enum_planet, seconds));

    return 0;
}