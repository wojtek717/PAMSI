//
// Created by Wojciech Konury on 02/06/2019.
//

#ifndef CHECKERS_MOVEMENT_H
#define CHECKERS_MOVEMENT_H


#include "Cell.h"

struct Movement {
    Cell from;
    Cell dest;
    int score;

    Movement(Cell from, Cell dest);
    Movement();
    void SetMovement(Cell from, Cell dest);
    void SetScore(int score);
};


#endif //CHECKERS_MOVEMENT_H
