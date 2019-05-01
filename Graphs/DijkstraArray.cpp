//
// Created by Wojciech Konury on 15/04/2019.
//

#include <iostream>
#include "DijkstraArray.h"
#include "Vertex.h"

#define INFINITY 9999999


/* SPT - Shortest Path Tree
 * Jezeli dany index sptSet[i] == true to wierzcholek i znajduje się w drzewie SPT*/

/* Funkcja znajduje najblizszy wierzcholek od wierzcholkow znajdujacych sie w drzewie SPT */
int DijkstraArray::shortestPath(std::vector<Vertex> vertices, std::vector<bool> sptSet) {
    int min = INFINITY;
    int minIndex;

    for (int v = 0; v < verticesAmount; v++){
        if (!sptSet[v] && vertices[v].distance <= min){
            min = vertices[v].distance;
            minIndex = v;
        }
    }

    return minIndex;
}

void DijkstraArray::ExecuteAlghoritm(std::vector<std::vector<int>> graph, int start) {
    std::vector<Vertex> vertices; //Tablica zawierajaca odleglosc od startu do wierzcholka i
    std::vector<bool> sptSet; //Tablica trzymajaca informacje czy dany wierzcholek jest w SPT

    Vertex vertex;


    // Zainicjalizuj wszystkie odleglosci jako inf
    for (int i = 0; i < verticesAmount; i++){
        vertex.index = i;
        vertices.push_back(vertex);
        sptSet.push_back(false);
    }



    //Znajdz najkrotsza sciezke dla kazdego z wierzcholka
    for (int i = 0; i < verticesAmount - 1; i++)
    {
        //Znajdz wierzcholek do ktorego droga jest najkrotsza
        int u = shortestPath(vertices, sptSet);

        //Dodaj ten wierzcholek do SPT
        sptSet[u] = true;

        std::vector<int> path;

        //Uaktualnij odleglosc sasiednich wierzcholkow od wybranego
        for (int v = 0; v < verticesAmount; v++){

            if (!sptSet[v] && graph[u][v] && vertices[u].distance != INFINITY
                && vertices[u].distance+graph[u][v] < vertices[v].distance){
                vertices[v].distance = vertices[u].distance + graph[u][v];
                vertices[v].parent = &vertices[u];

            }
        }
    }


    //Wypisz wynik
    printOutput(vertices);

}

void DijkstraArray::printOutput(std::vector<Vertex> vertices) {

    std::cout << "Vertex --- Distance from start --- Path" << std::endl;
    for (int j = 0; j < verticesAmount; ++j) {
        std::cout << "(" << vertices[j].index << ")" << " --- " << vertices[j].distance << " --- ";

        Vertex *parent = vertices[j].parent;
        while (parent != nullptr){
            std::cout << " -> (" << parent->index << ")";
            parent = parent->parent;
        }
        std::cout << std::endl;
    }
}

DijkstraArray::DijkstraArray(int verticesAmount) {
    this->verticesAmount = verticesAmount;
}
