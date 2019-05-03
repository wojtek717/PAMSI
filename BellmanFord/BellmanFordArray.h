//
// Created by Wojciech Konury on 01/05/2019.
//

#ifndef BELLMANFORD_BELLMANFORDARRAY_H
#define BELLMANFORD_BELLMANFORDARRAY_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Vertex.h"
#include "Edge.h"


class BellmanFordArray {
private:
    int verticesAmount;
    std::vector<std::vector<int>> graph;
    std::vector<Vertex> vertices; //Tablica zawierajaca odleglosc od startu do wierzcholka i
    bool isNegativeCircle;

public:
    BellmanFordArray(int verticesAmount);
    void AddEdge(Edge edge);
    void GenerateGraph(int fill);
    void ExecuteAlghoritm(int start);
    void PrintOutput(std::string fileName);

};


#endif //BELLMANFORD_BELLMANFORDARRAY_H
