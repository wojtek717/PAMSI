//
// Created by Wojciech Konury on 07/05/2019.
//

#include "ListGraph.h"

ListGraph::ListGraph(int verticesAmomunt) {
    this->verticesAmomunt = verticesAmomunt;
    this->isNegativeCircle = false;

    std::vector<std::pair<int,int>> v;

    for (int i = 0; i < verticesAmomunt; ++i) {
        adjList.push_back(v);
    }
}

void ListGraph::addEdge(Edge edge) {
    adjList[edge.startIndex].push_back(std::make_pair(edge.endIndex, edge.distance));
}

void ListGraph::PrintGraph() {
    std::cout << "Graph: " << std::endl;
    for (int i = 0; i < adjList.size(); ++i) {
        std::cout << "(" << i << "): ";
        for (int j = 0; j < adjList[i].size(); ++j) {
            std::cout << "[(" << adjList[i][j].first << ") " << adjList[i][j].second << "]";
        }
        std::cout << std::endl;
    }
}

void ListGraph::PrintResoult() {
    std::cout << "Vertex --- Distance from start --- Path" << std::endl;
    for (int j = 0; j < verticesAmomunt; ++j) {
        std::cout << "(" << vertices[j].index << ")" << " --- " << vertices[j].distance << " --- ";

        Vertex *parent = vertices[j].parent;
        while (parent != nullptr){
            std::cout << " -> (" << parent->index << ")";
            parent = parent->parent;
        }
        std::cout << std::endl;
    }
}

void ListGraph::BellmanFord(int start) {

}

void ListGraph::Dijkstra(int start) {

}
