//
// Created by Wojciech Konury on 02/06/2019.
//

#include "Movement.h"

Movement::Movement(Cell from, Cell dest) {
    this->from = from;
    this->dest = dest;
    this->score = 0;
}

void Movement::SetMovement(Cell from, Cell dest) {
    this->from = from;
    this->dest = dest;
}

void Movement::SetScore(int score) {
    this->score = score;
}

Movement::Movement() {
    this->from = Cell();
    this->dest = Cell();
    this->score = 0;
}
