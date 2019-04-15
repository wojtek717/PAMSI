//
// Created by Wojciech Konury on 15/04/2019.
//

#include <iostream>
#include "DijkstraArray.h"
#define INFINITY 9999999


/* SPT - Shortest Path Tree
 * Jezeli dany index sptSet[i] == true to wierzcholek i znajduje się w drzewie SPT*/

/* Funkcja znajduje najblizszy wierzcholek od wierzcholkow znajdujacych sie w drzewie SPT */
int DijkstraArray::shortestPath(std::vector<int> dist, std::vector<bool> sptSet) {
    int min = INFINITY;
    int minIndex;

    for (int v = 0; v < vertices; v++){
        if (!sptSet[v] && dist[v] <= min){
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void DijkstraArray::ExecuteAlghoritm(std::vector<std::vector<int>> graph, int start) {
    std::vector<int> dist; //Tablica zawierajaca odleglosc od startu do wierzcholka i
    std::vector<bool> sptSet; //Tablica trzymajaca informacje czy dany wierzcholek jest w SPT
    std::vector<int> parent(vertices, start);


    // Zainicjalizuj wszystkie odleglosci jako inf
    for (int i = 0; i < vertices; i++){
        dist.push_back(INFINITY);
        sptSet.push_back(false);
    }

    //Odleglosc startu do startu to zawsze 0
    dist[start] = 0;


    //Znajdz najkrotsza sciezke dla kazdego z wierzcholka
    for (int i = 0; i < vertices - 1; i++)
    {
        //Znajdz wierzcholek do ktorego droga jest najkrotsza
        int u = shortestPath(dist, sptSet);

        //Dodaj ten wierzcholek do SPT
        sptSet[u] = true;

        std::vector<int> path;

        std::cout << std::endl << " ## ";
        //Uaktualnij odleglosc sasiednich wierzcholkow od wybranego
        for (int v = 0; v < vertices; v++){

            if (!sptSet[v] && graph[u][v] && dist[u] != INFINITY
                && dist[u]+graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;

            }
        }
    }


    //Wypisz wynik
    printOutput(dist, parent);

}

void DijkstraArray::printOutput(std::vector<int> dist, std::vector<int> parent) {

    std::cout << "Vertex --- Distance from start --- Parent" << std::endl;
    for (int j = 0; j < vertices; ++j) {
        std::cout << j << " --- " << dist[j] << " --- " << parent[j] << std::endl;
    }
}

DijkstraArray::DijkstraArray(int vertices) {
    this->vertices = vertices;
}
