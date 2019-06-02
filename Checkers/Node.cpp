//
// Created by Wojciech Konury on 02/06/2019.
//

#include "Node.h"

Node::Node(std::vector<std::vector<Cell>> board, Movement movement) {
    this->subtree = std::vector<Node>();
    this->movement = movement;
    this->simulatedBoard = board;
}
