//
// Created by Wojciech Konury on 01/05/2019.
//

#include "BellmanFordArray.h"
#include "Edge.h"

BellmanFordArray::BellmanFordArray(int verticesAmount) {
    this->verticesAmount = verticesAmount;
    isNegativeCircle = false;
}

void BellmanFordArray::ExecuteAlghoritm(std::vector<std::vector<int>> graph, int start) {
    Vertex vertex;
    Edge edge;
    std::vector<Edge> edges;


    // Zainicjalizuj wszystkie odleglosci jako inf
    for (int i = 0; i < verticesAmount; i++){
        vertex.index = i;
        vertices.push_back(vertex);
    }

    //Odleglosc startu do startu to zawsze 0
    vertices[start].distance = 0;

    for (int j = 0; j < verticesAmount; ++j) {
        for (int i = 0; i < verticesAmount; ++i) {
            if (graph[j][i] != 0){
                edge.startIndex = j;
                edge.endIndex = i;
                edge.distance = graph[j][i];

                edges.push_back(edge);
            }
        }
    }

    for (int i = 0; i < (verticesAmount - 1); ++i) {
        for (int k = 0; k < edges.size(); ++k){
            if(vertices[edges[k].endIndex].distance > vertices[edges[k].startIndex].distance + edges[k].distance){
                vertices[edges[k].endIndex].distance = vertices[edges[k].startIndex].distance + edges[k].distance;
            }
        }
    }

    for (int k = 0; k < edges.size(); ++k){
        if(vertices[edges[k].endIndex].distance > vertices[edges[k].startIndex].distance + edges[k].distance){
            isNegativeCircle = true;
            break;
        }
    }



}

void BellmanFordArray::PrintOutput() {
    if(isNegativeCircle){
        std::cout << "NEGATIVE CIRCLE!" << std::endl;
    }

    std::cout << "Vertex --- Distance from start" << std::endl;

    for (int i = 0; i < verticesAmount; ++i) {
        std::cout << "(" << i << ") --- " << vertices[i].distance << std::endl;
    }
}
