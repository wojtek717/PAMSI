//
// Created by Wojciech Konury on 02/06/2019.
//

#ifndef CHECKERS_CAPTURE_H
#define CHECKERS_CAPTURE_H


#include "Cell.h"

struct Capture {
    Cell from;
    Cell dest;
    Cell capturePos;
    int score;

    Capture(Cell from, Cell dest, Cell capturePos, bool isCapture);
    Capture();
    void SetMovement(Cell from, Cell dest, Cell capturePos);
    void SetScore(int score);
    bool IsCapture();
    void SetIsCapture(bool isCapture);

private:
    bool isCapture;
};


#endif //CHECKERS_CAPTURE_H
