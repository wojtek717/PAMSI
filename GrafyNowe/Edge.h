//
// Created by Wojciech Konury on 01/05/2019.
//

#ifndef BELLMANFORD_EDGE_H
#define BELLMANFORD_EDGE_H


class Edge {
public:
    int startIndex;
    int endIndex;
    int distance;

    Edge(int start, int end, int dist);
    Edge();
};


#endif //BELLMANFORD_EDGE_H
