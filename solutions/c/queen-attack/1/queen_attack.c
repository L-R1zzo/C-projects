#include "queen_attack.h"
#include <stdlib.h>

attack_status_t can_attack(position_t queen1, position_t queen2){
    if (queen1.row == queen2.row && queen1.column == queen2.column){
        return INVALID_POSITION;
    }
    
    if (queen1.row <= 7 && queen2.row <= 7 && queen1.column <= 7 && queen2.column <= 7){
        if (queen1.row == queen2.row){
            return CAN_ATTACK;
        } else if (queen1.column == queen2.column){
            return CAN_ATTACK;
        } else if (abs(queen1.row - queen2.row) == abs(queen1.column - queen2.column)){
            return CAN_ATTACK;
        } else {
            return CAN_NOT_ATTACK;
        }
    } else {
        return INVALID_POSITION;
    }
}