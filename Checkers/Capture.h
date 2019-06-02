//
// Created by Wojciech Konury on 02/06/2019.
//

#ifndef CHECKERS_CAPTURE_H
#define CHECKERS_CAPTURE_H


#include "Cell.h"

struct Capture {
    bool isCapture;
    Cell from;
    Cell dest;
    Cell capturePos;
    int score;

    Capture(Cell from, Cell dest, Cell capturePos, bool isCapture );
    Capture();
    void SetCapture(Cell from, Cell dest, Cell capturePos);
    void SetScore(int score);
};


#endif //CHECKERS_CAPTURE_H
