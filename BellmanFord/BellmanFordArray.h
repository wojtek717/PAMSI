//
// Created by Wojciech Konury on 01/05/2019.
//

#ifndef BELLMANFORD_BELLMANFORDARRAY_H
#define BELLMANFORD_BELLMANFORDARRAY_H

#include <iostream>
#include <vector>
#include "Vertex.h"


class BellmanFordArray {
private:
    int verticesAmount;
    std::vector<Vertex> vertices; //Tablica zawierajaca odleglosc od startu do wierzcholka i

public:
    BellmanFordArray(int verticesAmount);
    void ExecuteAlghoritm(std::vector<std::vector<int>> graph, int start);
    void PrintOutput();

};


#endif //BELLMANFORD_BELLMANFORDARRAY_H
