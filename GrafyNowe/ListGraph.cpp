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
    Vertex vertex;
    int dest;
    int cost;

    // Zainicjalizuj wszystkie odleglosci jako inf
    vertices.clear();
    for (int i = 0; i < verticesAmomunt; i++){
        vertex.index = i;
        vertices.push_back(vertex);
    }

    //Odleglosc startu do startu to zawsze 0
    vertices[start].distance = 0;

    for (int i = 0; i < verticesAmomunt - 1; ++i) { //Liczba iteracji = v-1
        for (int src = 0; src < verticesAmomunt; ++src) {
            for (int n = 0; n < adjList[src].size(); ++n) {
                dest = adjList[src][n].first;
                cost = adjList[src][n].second;

                if(vertices[dest].distance > vertices[src].distance + cost){
                    vertices[dest].distance = vertices[src].distance + cost;
                    vertices[dest].parent = &vertices[src];
                }
            }
        }
    }

    for (int src = 0; src < verticesAmomunt; ++src) {
        for (int n = 0; n < adjList[src].size(); ++n) {
            dest = adjList[src][n].first;
            cost = adjList[src][n].second;

            if(vertices[dest].distance > vertices[src].distance + cost){
                isNegativeCircle = true;
                break;
            }
        }
    }
}

void ListGraph::Dijkstra(int start) {
    Vertex vertex;

    // Zainicjalizuj wszystkie odleglosci jako inf
    vertices.clear();
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
