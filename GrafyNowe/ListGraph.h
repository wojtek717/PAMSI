//
// Created by Wojciech Konury on 07/05/2019.
//

#ifndef GRAFYNOWE_LISTGRAPH_H
#define GRAFYNOWE_LISTGRAPH_H

#include <iostream>
#include "Graph.h"

class ListGraph : public Graph{
private:
    std::vector< std::vector<std::pair<int,int >>> adjList;

    void addEdge(Edge edge) override;
public:
    ListGraph(int verticesAmomunt);

    void PrintGraph() override;
    void PrintResoult() override;

    void BellmanFord(int start) override;
    void Dijkstra(int start) override;
};


#endif //GRAFYNOWE_LISTGRAPH_H
