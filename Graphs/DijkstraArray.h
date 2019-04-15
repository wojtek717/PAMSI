//
// Created by Wojciech Konury on 15/04/2019.
//

#ifndef GRAPHS_DIJKSTRAARRAY_H
#define GRAPHS_DIJKSTRAARRAY_H

#include <vector>


class DijkstraArray {
private:
    int vertices;

    int shortestPath(std::vector<int> dist, std::vector<bool> sptSet);
    void printOutput(std::vector<int> dist, std::vector<int> parent);

public:
    DijkstraArray(int vertices);
    void ExecuteAlghoritm(std::vector<std::vector<int>> graph, int start);
};


#endif //GRAPHS_DIJKSTRAARRAY_H
