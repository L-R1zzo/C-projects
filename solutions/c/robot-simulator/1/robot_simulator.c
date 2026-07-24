#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y){
    robot_status_t new_robot;
    new_robot.direction = direction;
    new_robot.position.x = x;
    new_robot.position.y = y;
    return new_robot;
}

void robot_move(robot_status_t *robot, const char *commands){
    
    // advance north correspond to +1 in y assis
    // advance south correspond to -1 in y assis
    // advance east correspond to +1 in x assis    
    // advance west correspond to -1 in x assis

    for (int n = 0; commands[n] != '\0'; n++){
        switch (commands[n]){
            case 'A':
                switch (robot->direction){
                    case DIRECTION_NORTH:
                        robot->position.y += 1;
                        break;
                    case DIRECTION_EAST:
                        robot->position.x += 1;
                        break;
                    case DIRECTION_SOUTH:
                        robot->position.y -= 1;
                        break;
                    case DIRECTION_WEST:
                        robot->position.x -= 1;
                        break;
                }
                break;
            case 'R':
                switch (robot->direction){
                    case DIRECTION_NORTH:
                        robot->direction = DIRECTION_EAST;
                        break;
                    case DIRECTION_EAST:
                        robot->direction = DIRECTION_SOUTH;
                        break;
                    case DIRECTION_SOUTH:
                        robot->direction = DIRECTION_WEST;
                        break;
                    case DIRECTION_WEST:
                        robot->direction = DIRECTION_NORTH;
                        break;
                }
                break;
            case 'L':
                switch (robot->direction){
                    case DIRECTION_NORTH:
                        robot->direction = DIRECTION_WEST;
                        break;
                    case DIRECTION_EAST:
                        robot->direction = DIRECTION_NORTH;
                        break;
                    case DIRECTION_SOUTH:
                        robot->direction = DIRECTION_EAST;
                        break;
                    case DIRECTION_WEST:
                        robot->direction = DIRECTION_SOUTH;
                        break;
                }    
                break;
        } 
    }
}