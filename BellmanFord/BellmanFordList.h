//
// Created by Wojciech Konury on 20/04/2019.
//

#ifndef BELLMANFORD_BELLMANFORDLIST_H
#define BELLMANFORD_BELLMANFORDLIST_H


#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include "Vertex.h"
#include "Node.h"
#include "Edge.h"

class BellmanFordList {
private:
    int verticesAmmount;
    int edgesAmmount;
    bool isNegativeCircle;

    std::vector<Vertex> vertices;
    std::vector< std::vector<Node>> adjList;

public:
    BellmanFordList(int verticesAmmount);
    void AddEdge(int source, int destination, int cost);
    void AddEdge(int source, Node node);
    void AddEdge(Edge edge);
    void GenerateGraph(int fill);

    void ExecuteAlgorithm(int start);
    void PrintOutput(std::string fileName);
};


#endif //BELLMANFORD_BELLMANFORDLIST_H
