//
// Created by Wojciech Konury on 17/04/2019.
//

#include "DijkstraList.h"
#include "Vertex.h"

bool DijkstraList::FormAdjList(std::string fileName) {
    int edges;

    int source;
    int destination;
    int cost;

    std::fstream file;
    file.open(fileName, std::ios::in);

    if(!file.good()){
        return false;
    }

    file >> verticesAmmount;
    file >> edges;

    for(int i = 0; i < verticesAmmount; ++i) {
        // Stworz vector reprezeentujacy wiersz i dodaj go do listy
        std::vector<std::pair<int, int> > row;
        adjList.push_back(row);
    }

    for(int k = 0; k < edges; ++k){
        file >> source;
        file >> destination;
        file >> cost;

        // Polaczenie w dwie strony
        adjList[source].push_back(std::make_pair(destination, cost));
        adjList[destination].push_back(std::make_pair(source, cost));
    }

    return true;
}

void DijkstraList::DijkstraSP(int &start) {
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

    PrintShortestPath(start);
}

void DijkstraList::PrintShortestPath(int &start) {
    std::cout << "Vertex --- Distance from start --- Path" << std::endl;
    for (int j = 0; j < verticesAmmount; ++j) {
        std::cout << "(" << vertices[j].index << ")" << " --- " << vertices[j].distance << " --- ";

        Vertex *parent = vertices[j].parent;
        while (parent != nullptr){
            std::cout << " -> (" << parent->index << ")";
            parent = parent->parent;
        }
        std::cout << std::endl;
    }
}
