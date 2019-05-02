//
// Created by Wojciech Konury on 20/04/2019.
//

#include "BellmanFordList.h"


BellmanFordList::BellmanFordList(int verticesAmmount) {
    this->verticesAmmount = verticesAmmount;
    this->edgesAmmount = 0;
    this->isNegativeCircle = false;

    std::vector<Node> v;

    for (int i = 0; i < verticesAmmount; ++i) {
        adjList.push_back(v);
    }
}

void BellmanFordList::AddEdge(int source, int destination, int cost) {
    Node n(destination, cost);

    this->adjList[source].push_back(n);
    edgesAmmount++;
}

void BellmanFordList::AddEdge(int source, Node node) {
    this->adjList[source].push_back(node);
    edgesAmmount++;
}

void BellmanFordList::ExecuteAlgorithm(int start) {
    Vertex vertex;

    // Zainicjalizuj wszystkie odleglosci jako inf
    for (int i = 0; i < verticesAmmount; i++){
        vertex.index = i;
        vertices.push_back(vertex);
    }

    //Odleglosc startu do startu to zawsze 0
    vertices[start].distance = 0;

    int dest;
    int cost;

    for (int i = 0; i < verticesAmmount - 1; ++i) { //Liczba iteracji = v-1
        for (int src = 0; src < verticesAmmount; ++src) {
            for (int n = 0; n < adjList[src].size(); ++n) {
                dest = adjList[src][n].destination;
                cost = adjList[src][n].cost;

                if(vertices[dest].distance > vertices[src].distance + cost){
                    vertices[dest].distance = vertices[src].distance + cost;
                }
            }
        }
    }

    for (int src = 0; src < verticesAmmount; ++src) {
        for (int n = 0; n < adjList[src].size(); ++n) {
            dest = adjList[src][n].destination;
            cost = adjList[src][n].cost;

            if(vertices[dest].distance > vertices[src].distance + cost){
                isNegativeCircle = true;
                break;
            }
        }
    }
}

void BellmanFordList::PrintOutput() {
    if(isNegativeCircle){
        std::cout << "NEGATIVE CIRCLE!" << std::endl;
    }

    std::cout << "Vertex --- Distance from start" << std::endl;

    for (int i = 0; i < verticesAmmount; ++i) {
        std::cout << "(" << i << ") --- " << vertices[i].distance << std::endl;
    }
}
