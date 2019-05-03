//
// Created by Wojciech Konury on 02/05/2019.
//

#include "Node.h"

Node::Node() {
    this->destination = 99999;
    this->cost = 0;
}

Node::Node(int dest, int cost) {
    this->destination = dest;
    this->cost = cost;
}
