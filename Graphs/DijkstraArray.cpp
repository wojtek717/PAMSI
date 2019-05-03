//
// Created by Wojciech Konury on 15/04/2019.
//


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

void DijkstraArray::ExecuteAlghoritm(int start) {
    std::vector<bool> sptSet; //Tablica trzymajaca informacje czy dany wierzcholek jest w SPT

    Vertex vertex;


    // Zainicjalizuj wszystkie odleglosci jako inf
    for (int i = 0; i < verticesAmount; i++){
        vertex.index = i;
        vertices.push_back(vertex);
        sptSet.push_back(false);
    }

    //Odleglosc startu do startu to zawsze 0
    vertices[start].distance = 0;

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
}

void DijkstraArray::PrintOutput(std::string fileName) {
    std::fstream outputFile;

    outputFile.open(fileName, std::ios::app);
    if(outputFile.good())
    {
        outputFile << "Graph:" << std::endl;
        for (int i = 0; i < verticesAmount; ++i) {
            for (int j = 0; j < verticesAmount; ++j) {
                outputFile << graph[i][j] << " ";
            }
            outputFile << std::endl;
        }

        outputFile << "Vertex --- Distance from start --- Path" << std::endl;
        for (int j = 0; j < verticesAmount; ++j) {
            outputFile << "(" << vertices[j].index << ")" << " --- " << vertices[j].distance << " --- ";

            Vertex *parent = vertices[j].parent;
            while (parent != nullptr){
                outputFile << " -> (" << parent->index << ")";
                parent = parent->parent;
            }
            outputFile << std::endl;
        }

        outputFile.close();
    }
}

DijkstraArray::DijkstraArray(int verticesAmount) {
    this->verticesAmount = verticesAmount;

    std::vector<int> vector;

    for (int i = 0; i < verticesAmount; ++i) {
        graph.push_back(vector);
        for (int k = 0; k < verticesAmount; ++k) {
            graph[i].push_back(0);
        }
    }
}

void DijkstraArray::AddEdge(Edge edge) {
    graph[edge.startIndex][edge.endIndex] = edge.distance;
}

void DijkstraArray::GenerateGraph(int fill) {
    if(fill > 100){
        fill = 100;
    }

    if(fill < 0){
        fill = 0;
    }


    Edge edge;
    std::vector<Edge> edgeList;

    int maxEdges = verticesAmount * (verticesAmount -1);
    int edgesLeft = (maxEdges * fill) / 100;
    int randIndex;

    for (int i = 0; i < verticesAmount; ++i) {

        for (int k = 0; k < verticesAmount; ++k) {

            if(i != k){
                edge.startIndex = i;
                edge.endIndex = k;
                edge.distance = rand() % 1000;

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

