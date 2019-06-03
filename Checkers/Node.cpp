//
// Created by Wojciech Konury on 02/06/2019.
//

#include "Node.h"

Node::Node(std::vector<std::vector<Cell>> board, Movement movement) {
    this->subtree = std::vector<Node>();
    this->movement = movement;
    this->simulatedBoard = board;
    this->IsCapture = false;
    this->points = movement.score;

    this->capture = Capture();
}

Node::Node(std::vector<std::vector<Cell>> board, Capture capture) {
    this->subtree = std::vector<Node>();
    this->capture = capture;
    this->simulatedBoard = board;
    this->IsCapture = true;
    this->points = capture.score;

    this->movement = Movement();
}
