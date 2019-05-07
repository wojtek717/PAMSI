//
// Created by Wojciech Konury on 01/05/2019.
//

#include "Edge.h"

Edge::Edge(int start, int end, int dist) {
    this->startIndex = start;
    this->endIndex = end;
    this->distance = dist;
}

Edge::Edge() {
    this->startIndex = 0;
    this->endIndex = 0;
    this->distance = 0;
}
