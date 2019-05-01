//
// Created by Wojciech Konury on 15/04/2019.
//

#ifndef GRAPHS_VERTEX_H
#define GRAPHS_VERTEX_H


class Vertex {
public:
    int index;
    int distance;
    Vertex *parent;

    Vertex();
};


#endif //GRAPHS_VERTEX_H
