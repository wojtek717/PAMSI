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

class DijkstraList {
private:
    int verticesAmmount;
    std::vector< std::vector<std::pair<int, int> > > adjList;
    //std::vector<int> dist;

public:
    bool FormAdjList(std::string fileName);

    void DijkstraSP(int &start);

    void PrintShortestPath(std::vector<Vertex> &vertices, int &start);


};


#endif //GRAPHS_DIJKSTRALIST_H
