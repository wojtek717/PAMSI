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

    /* To w jakas funcke z pliku */
    for(int i = 0; i < verticesAmmount; i++)
    {
        // Create a vector to represent a row, and add it to the adjList.
        std::vector<std::pair<int, int> > row;
        adjList.push_back(row);
    }

    for(int k = 0; k < edges; ++k){
        file >> source;
        file >> destination;
        file >> cost;

        adjList[source].push_back(std::make_pair(destination, cost));
        adjList[destination].push_back(std::make_pair(source, cost));
    }

    return true;



}

void DijkstraList::DijkstraSP(int &start) {
    std::cout << "\nGetting the shortest path from " << start << " to all other nodes.\n";
    Vertex vertex;

    // Initialize all source->vertex as infinite.
    int n = adjList.size();
    for(int i = 0; i < n; i++)
    {
        //dist.push_back(INFINITY); // Define "infinity" as necessary by constraints.
        vertex.index = i;
        vertices.push_back(vertex);
    }

    // Create a PQ.
    std::priority_queue<std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;

    // Add source to pq, where distance is 0.
    pq.push(std::make_pair(start, 0));
    vertices[start].distance = 0;

    // While pq isn't empty...
    while(pq.empty() == false)
    {
        // Get min distance vertex from pq. (Call it u.)
        int u = pq.top().first;
        pq.pop();

        // Visit all of u's friends. For each one (called v)....
        for(int i = 0; i < adjList[u].size(); i++)
        {
            int v = adjList[u][i].first;
            int weight = adjList[u][i].second;

            // If the distance to v is shorter by going through u...
            if(vertices[v].distance > vertices[u].distance + weight)
            {
                // Update the distance of v.
                vertices[v].distance = vertices[u].distance + weight;
                // Insert v into the pq.
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
