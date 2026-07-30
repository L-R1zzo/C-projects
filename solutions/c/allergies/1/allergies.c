#include "allergies.h"

allergen_list_t get_allergens(int score){
    allergen_list_t allergies;
    allergies.count = 0;
    
    if (score & 1){
        allergies.count++;
        allergies.allergens[ALLERGEN_EGGS] = true;
    } else {
        allergies.allergens[ALLERGEN_EGGS] = false;
    } 

    if (score & 2){
        allergies.count++;
        allergies.allergens[ALLERGEN_PEANUTS] = true;
    } else {
        allergies.allergens[ALLERGEN_PEANUTS] = false;
    } 

    if (score & 4){
        allergies.count++;
        allergies.allergens[ALLERGEN_SHELLFISH] = true;
    } else {
        allergies.allergens[ALLERGEN_SHELLFISH] = false;
    } 

    if (score & 8){
        allergies.count++;
        allergies.allergens[ALLERGEN_STRAWBERRIES] = true;
    } else {
        allergies.allergens[ALLERGEN_STRAWBERRIES] = false;
    } 

    if (score & 16){
        allergies.count++;
        allergies.allergens[ALLERGEN_TOMATOES] = true;
    } else {
        allergies.allergens[ALLERGEN_TOMATOES] = false;
    } 

    if (score & 32){
        allergies.count++;
        allergies.allergens[ALLERGEN_CHOCOLATE] = true;
    } else {
        allergies.allergens[ALLERGEN_CHOCOLATE] = false;
    } 

    if (score & 64){
        allergies.count++;
        allergies.allergens[ALLERGEN_POLLEN] = true;
    } else {
        allergies.allergens[ALLERGEN_POLLEN] = false;
    } 

    if (score & 128){
        allergies.count++;
        allergies.allergens[ALLERGEN_CATS] = true;
    } else {
        allergies.allergens[ALLERGEN_CATS] = false;
    } 

    return allergies;
}

bool is_allergic_to(allergen_t allergen, int score){
    switch (allergen){
        case 0:
            return score & 1; 
        case 1:
            return score & 2;
        case 2:
            return score & 4;
        case 3:
            return score & 8;
        case 4:
            return score & 16;
        case 5:
            return score & 32;
        case 6:
            return score & 64;
        case 7:
            return score & 128;
        default:
            return false;
            
    }
}