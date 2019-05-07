//
// Created by Wojciech Konury on 07/05/2019.
//

#ifndef GRAFYNOWE_MATRIXGRAPH_H
#define GRAFYNOWE_MATRIXGRAPH_H

#include <iostream>
#include "Graph.h"

class MatrixGraph : public Graph {
private:
    std::vector<std::vector<int>> graph;

    void addEdge(Edge edge) override;
    int shortestPath(std::vector<Vertex> vertices, std::vector<bool> sptSet);

public:
    MatrixGraph(int verticesAmomunt);

    void PrintGraph() override;
    void PrintResoult() override;

    void BellmanFord(int start) override;
    void Dijkstra(int start) override;
};


#endif //GRAFYNOWE_MATRIXGRAPH_H
