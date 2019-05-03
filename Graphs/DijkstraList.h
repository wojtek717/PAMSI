//
// Created by Wojciech Konury on 17/04/2019.
//

#ifndef GRAPHS_DIJKSTRALIST_H
#define GRAPHS_DIJKSTRALIST_H

#define INFINITY 9999999

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "Vertex.h"
#include "Node.h"
#include "Edge.h"

class DijkstraList {
private:
    int verticesAmmount;
    std::vector<Vertex> vertices;
    std::vector< std::vector<std::pair<int,int >>> adjList;

public:

    DijkstraList(int verticesAmmount);
    void AddEdge(int source, int destination, int cost);
    void AddEdge(Edge edge);
    void GenerateGraph(int fill);
    void ExecuteAlgorithm(int start);
    void PrintShortestPath(std::string fileName);


};


#endif //GRAPHS_DIJKSTRALIST_H
