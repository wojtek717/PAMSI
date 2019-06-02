//
// Created by Wojciech Konury on 02/06/2019.
//

#include "Capture.h"

Capture::Capture(Cell from, Cell dest, Cell capturePos, bool isCapture) {
    this->from = from;
    this->dest = dest;
    this->capturePos = capturePos;
    this->score = 0;
    this->isCapture = isCapture;
}

Capture::Capture() {
    this->from = Cell();
    this->dest = Cell();
    this->capturePos = Cell();
    this->score = 0;
    this->isCapture = false;
}

void Capture::SetCapture(Cell from, Cell dest, Cell capturePos) {
    this->from = from;
    this->dest = dest;
    this->capturePos = capturePos;
}

void Capture::SetScore(int score) {
    this->score = score;
}
