//
// Created by Wojciech Konury on 02/06/2019.
//

#ifndef CHECKERS_NODE_H
#define CHECKERS_NODE_H


#include <vector>
#include <iostream>
#include "Cell.h"
#include "Movement.h"
#include "Capture.h"

class Node {
public:
    std::vector<std::vector<Cell>> simulatedBoard; //Stan planszy po wykonanym ruchu
    Movement movement;
    Capture capture;
    bool IsCapture;
    std::vector<Node> subtree;
    int points;

    Node(std::vector<std::vector<Cell>>, Movement movement);
    Node(std::vector<std::vector<Cell>>, Capture capture);
};


#endif //CHECKERS_NODE_H
