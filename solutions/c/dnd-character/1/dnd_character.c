#include "dnd_character.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

dnd_character_t make_dnd_character(void){
    srand(time(NULL));
    dnd_character_t character;
    character.strength = ability();
    character.dexterity = ability();
    character.constitution = ability();
    character.intelligence = ability();
    character.wisdom = ability();
    character.charisma = ability();
    character.hitpoints = 10 + modifier(character.constitution);
    return character;
}

int ability(void){
    int dice[4];
    
    for (int i = 0; i < 4; i++){
        dice[i] = rand() % 6 + 1;
    }

    int selected = dice[0];
    for (int i = 1; i < 4; i++){
        if (selected > dice[i]){
            selected = dice[i];
        }
    }
    
    return dice[0] + dice[1] + dice[2] + dice[3] - selected;

}

int modifier(int score){
    return floor((score - 10) / 2.0);
}