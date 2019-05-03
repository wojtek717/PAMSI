//
// Created by Wojciech Konury on 17/04/2019.
//

#include "DijkstraList.h"
#include "Vertex.h"



void DijkstraList::ExecuteAlgorithm(int start) {
    Vertex vertex;

    // Zainicjalizuj wszystkie odleglosci jako inf
    int n = adjList.size();
    for(int i = 0; i < n; i++)
    {
        vertex.index = i;
        vertices.push_back(vertex);
    }

    std::priority_queue<std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;

    // Odleglosc od startu do startu zawsze = 0
    pq.push(std::make_pair(start, 0));
    vertices[start].distance = 0;


    while(!pq.empty())
    {
        // Dostan najblizszy wierzcholek
        int u = pq.top().first;
        pq.pop();

        // Sprawdz pozostale wierzcholki
        for(int i = 0; i < adjList[u].size(); i++)
        {
            int v = adjList[u][i].first;
            int weight = adjList[u][i].second;

            // Jezeli odleglosc do v jest mniejsza idac przez u
            if(vertices[v].distance > vertices[u].distance + weight)
            {
                vertices[v].distance = vertices[u].distance + weight;
                pq.push(std::make_pair(v, vertices[v].distance));
                vertices[v].parent = &vertices[u];
            }
        }
    }
}

void DijkstraList::PrintShortestPath(std::string fileName) {
    std::fstream outputFile;

    outputFile.open(fileName, std::ios::app);
    if(outputFile.good())
    {
        outputFile << "Graph: " << std::endl;
        for (int i = 0; i < adjList.size(); ++i) {
            outputFile << "(" << i << "): ";
            for (int j = 0; j < adjList[i].size(); ++j) {
                outputFile << "[(" << adjList[i][j].first << ") " << adjList[i][j].second << "]";
            }
            outputFile << std::endl;
        }

        outputFile << "Vertex --- Distance from start --- Path" << std::endl;
        for (int j = 0; j < verticesAmmount; ++j) {
            outputFile << "(" << vertices[j].index << ")" << " --- " << vertices[j].distance << " --- ";

            Vertex *parent = vertices[j].parent;
            while (parent != nullptr){
                outputFile << " -> (" << parent->index << ")";
                parent = parent->parent;
            }
            outputFile << std::endl;
        }
    }
}

DijkstraList::DijkstraList(int verticesAmmount) {
    this->verticesAmmount = verticesAmmount;

    std::vector<std::pair<int,int>> v;

    for (int i = 0; i < verticesAmmount; ++i) {
        adjList.push_back(v);
    }
}

void DijkstraList::AddEdge(int source, int destination, int cost) {
    adjList[source].push_back(std::make_pair(destination, cost));
}

void DijkstraList::AddEdge(Edge edge) {
    adjList[edge.startIndex].push_back(std::make_pair(edge.endIndex, edge.distance));
}

void DijkstraList::GenerateGraph(int fill) {
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



