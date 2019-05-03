//
// Created by Wojciech Konury on 15/04/2019.
//

#ifndef GRAPHS_DIJKSTRAARRAY_H
#define GRAPHS_DIJKSTRAARRAY_H

#include <vector>
#include <fstream>
#include <iostream>
#include "Vertex.h"
#include "Edge.h"


class DijkstraArray {
private:
    int verticesAmount;
    std::vector<Vertex> vertices;
    std::vector<std::vector<int>> graph;
    int shortestPath(std::vector<Vertex> vertices, std::vector<bool> sptSet);

public:
    DijkstraArray(int verticesAmount);
    void AddEdge(Edge edge);
    void GenerateGraph(int fill);
    void ExecuteAlghoritm(int start);
    void PrintOutput(std::string fileName);
};


#endif //GRAPHS_DIJKSTRAARRAY_H
