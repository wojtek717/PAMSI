//
// Created by Wojciech Konury on 20/04/2019.
//

#include "BellmanFordList.h"
#include "Edge.h"


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

void BellmanFordList::AddEdge(Edge edge) {
    Node n(edge.endIndex, edge.distance);

    this->adjList[edge.startIndex].push_back(n);
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
                    vertices[dest].parent = &vertices[src];
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

void BellmanFordList::PrintOutput(std::string fileName) {

    std::fstream outputFile;

    outputFile.open(fileName, std::ios::app);
    if(outputFile.good())
    {
        outputFile << "Graph: " << std::endl;
        for (int i = 0; i < adjList.size(); ++i) {
            outputFile << "(" << i << "): ";
            for (int j = 0; j < adjList[i].size(); ++j) {
                outputFile << "[(" << adjList[i][j].destination << ") " << adjList[i][j].cost << "]";
            }
            outputFile << std::endl;
        }

        if(isNegativeCircle){
            std::cout << "NEGATIVE CIRCLE!" << std::endl;
        }

        outputFile << "Vertex --- Distance from start --- Path" << std::endl;
        for (int j = 0; j < verticesAmmount; ++j) {
            outputFile << "(" << vertices[j].index << ")" << " --- " << vertices[j].distance << " --- ";

            if(!isNegativeCircle){
                Vertex *parent = vertices[j].parent;
                while (parent != nullptr){
                    outputFile << " -> (" << parent->index << ")";
                    parent = parent->parent;
                }
            }

            outputFile << std::endl;
        }
    }

}

void BellmanFordList::GenerateGraph(int fill) {
    if(fill > 100){
        fill = 100;
    }

    if(fill < 0){
        fill = 0;
    }


    Edge edge;
    std::vector<Edge> edgeList;

    int maxEdges = verticesAmmount * (verticesAmmount -1);
    int edgesLeft = (maxEdges * fill) / 100;
    int randIndex;

    for (int i = 0; i < verticesAmmount; ++i) {

        for (int k = 0; k < verticesAmmount; ++k) {

            if(i != k){
                edge.startIndex = i;
                edge.endIndex = k;

                if((rand() % 100) > 5){
                    edge.distance = rand() % 1000;
                } else{
                    edge.distance = (rand() % 5) * -1;
                }

                edgeList.push_back(edge);
            }
        }
    }

    while (edgesLeft > 0){
        randIndex = rand() % edgeList.size();

        AddEdge(edgeList[randIndex]);
        edgeList.erase(edgeList.begin() + randIndex);

        edgesLeft--;
    }

}


