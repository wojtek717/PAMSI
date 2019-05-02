//
// Created by Wojciech Konury on 02/05/2019.
//

#ifndef BELLMANFORD_NODE_H
#define BELLMANFORD_NODE_H


class Node {
public:
    int destination;
    int cost;

    Node();
    Node(int dest, int cost);
};


#endif //BELLMANFORD_NODE_H
