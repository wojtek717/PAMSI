//
// Created by Wojciech Konury on 07/05/2019.
//

#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int verticesAmomunt) {
    this->verticesAmomunt = verticesAmomunt;
    this->isNegativeCircle = false;

    std::vector<int> vector;

    for (int i = 0; i < verticesAmomunt; ++i) {
        graph.push_back(vector);
        for (int k = 0; k < verticesAmomunt; ++k) {
            graph[i].push_back(0);
        }
    }
}

void MatrixGraph::addEdge(Edge edge) {
    graph[edge.startIndex][edge.endIndex] = edge.distance;
}

void MatrixGraph::BellmanFord(int start) {
    Vertex vertex;

    // Zainicjalizuj wszystkie odleglosci jako inf
    vertices.clear();
    for (int i = 0; i < verticesAmomunt; i++){
        vertex.index = i;
        vertices.push_back(vertex);
    }

    //Odleglosc startu do startu to zawsze 0
    vertices[start].distance = 0;

    for (int k = 0; k < (verticesAmomunt - 1); ++k) {
        for (int i = 0; i < verticesAmomunt; ++i) {
            for (int j = 0; j < verticesAmomunt; ++j) {
                if (graph[i][j] != 0){
                    if(vertices[j].distance > vertices[i].distance + graph[i][j]){
                        vertices[j].distance = vertices[i].distance + graph[i][j];
                        vertices[j].parent = &vertices[i];


                    }
                }
            }
        }
    }

    for (int j = 0; j < verticesAmomunt; ++j) {
        for (int i = 0; i < verticesAmomunt; ++i) {
            if (graph[i][j] != 0){
                if(vertices[j].distance > vertices[i].distance + graph[i][j]){
                    isNegativeCircle = true;
                    break;
                }
            }
        }
    }
}

void MatrixGraph::Dijkstra(int start) {
    std::vector<bool> sptSet; //Tablica trzymajaca informacje czy dany wierzcholek jest w SPT

    Vertex vertex;

    // Zainicjalizuj wszystkie odleglosci jako inf
    vertices.clear();
    for (int i = 0; i < verticesAmomunt; i++){
        vertex.index = i;
        vertices.push_back(vertex);
        sptSet.push_back(false);
    }

    //Odleglosc startu do startu to zawsze 0
    vertices[start].distance = 0;

    //Znajdz najkrotsza sciezke dla kazdego z wierzcholka
    for (int i = 0; i < verticesAmomunt - 1; i++)
    {
        //Znajdz wierzcholek do ktorego droga jest najkrotsza
        int u = shortestPath(vertices, sptSet);

        //Dodaj ten wierzcholek do SPT
        sptSet[u] = true;

        std::vector<int> path;

        //Uaktualnij odleglosc sasiednich wierzcholkow od wybranego
        for (int v = 0; v < verticesAmomunt; v++){

            if (!sptSet[v] && graph[u][v] && vertices[u].distance != 999999
                && vertices[u].distance+graph[u][v] < vertices[v].distance){
                vertices[v].distance = vertices[u].distance + graph[u][v];
                vertices[v].parent = &vertices[u];

            }
        }
    }
}

void MatrixGraph::PrintGraph() {
    for (int i = 0; i < verticesAmomunt; ++i) {
        for (int j = 0; j < verticesAmomunt; ++j) {
            std::cout << graph[i][j] << "   ";
        }
        std::cout << std::endl;
    }
}

void MatrixGraph::PrintResoult() {
    if(isNegativeCircle){
        std::cout << "NEGATIVE CIRCLE!" << std::endl;
    }

    std::cout << "Vertex --- Distance from start --- Path" << std::endl;
    for (int j = 0; j < verticesAmomunt; ++j) {
        std::cout << "(" << vertices[j].index << ")" << " --- " << vertices[j].distance << " --- ";



        if(!isNegativeCircle){
            Vertex *parent = vertices[j].parent;
            while (parent != nullptr){
                std::cout << " -> (" << parent->index << ")";
                parent = parent->parent;
            }
        }

        std::cout << std::endl;
    }
}

int MatrixGraph::shortestPath(std::vector<Vertex> vertices, std::vector<bool> sptSet) {
    int min = 99999;
    int minIndex;

    for (int v = 0; v < verticesAmomunt; v++){
        if (!sptSet[v] && vertices[v].distance <= min){
            min = vertices[v].distance;
            minIndex = v;
        }
    }

    return minIndex;
}




