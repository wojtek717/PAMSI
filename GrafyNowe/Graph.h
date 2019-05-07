//
// Created by Wojciech Konury on 07/05/2019.
//

#ifndef GRAFYNOWE_GRAPH_H
#define GRAFYNOWE_GRAPH_H


#include <vector>
#include "Vertex.h"
#include "Edge.h"

class Graph {
private:

protected:
    int verticesAmomunt;
    bool isNegativeCircle;
    std::vector<Vertex> vertices;

    Graph();
    virtual void addEdge(Edge edge) = 0;

public:
    void GenerateGraph(bool negative, int fill);

    virtual void BellmanFord(int start) = 0;
    virtual void Dijkstra(int start) = 0;
    virtual void PrintGraph() = 0;
    virtual void PrintResoult() = 0;
};


#endif //GRAFYNOWE_GRAPH_H
