#include "statistics.h"

Statistics::Statistics()
{

}

void Statistics::saveMovement(int d_x, int d_y) {
    stepConsts movement;
    if (d_x == 0) {
        if (d_y > 0) {
            movement = STEP_DOWN;
        } else {
            movement = STEP_UP;
        }
        //movement = static_cast<stepConsts>(d_y);
    } else {
        if (d_x > 0) {
            movement = STEP_RIGHT;
        } else {
            movement = STEP_LEFT;
        }
        //movement = static_cast<stepConsts>(d_x);
    }
    game_movements_.push_back(movement);
    ++number_of_movements_;
}

stepConsts Statistics::lastMovement() {
    return game_movements_.last();
}


std::pair<int, int> Statistics::reverseMovement() {
    stepConsts step = game_movements_.last();
    std::pair<int, int> reversed_d;
    switch (step) {
    case STEP_UP: {
        reversed_d = std::make_pair(0, 64);
        break;
    }
    case STEP_LEFT: {
        reversed_d = std::make_pair(64, 0);
        break;
    }

    case STEP_DOWN: {
        reversed_d = std::make_pair(0, -64);
        break;
    }
    case STEP_RIGHT: {
        reversed_d = std::make_pair(-64, 0);
        break;
    }
    }
    return reversed_d;
}

