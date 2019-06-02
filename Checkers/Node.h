//
// Created by Wojciech Konury on 02/06/2019.
//

#ifndef CHECKERS_NODE_H
#define CHECKERS_NODE_H


#include <vector>
#include <iostream>
#include "Cell.h"
#include "Movement.h"

class Node {
public:
    std::vector<std::vector<Cell>> simulatedBoard; //Stan planszy po wykonanym ruchu
    Movement movement;
    std::vector<Node> subtree;

    Node(std::vector<std::vector<Cell>>, Movement movement);
};


#endif //CHECKERS_NODE_H
