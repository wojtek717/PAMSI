//
// Created by Wojciech Konury on 17/04/2019.
//

#include "DijkstraList.h"

void DijkstraList::FormAdjList(int vertices) {


    /* To w jakas funcke z pliku */
    for(int i = 0; i < vertices; i++)
    {
        // Create a vector to represent a row, and add it to the adjList.
        std::vector<std::pair<int, int> > row;
        adjList.push_back(row);
    }


    adjList[0].push_back(std::make_pair(1, 2));
    adjList[0].push_back(std::make_pair(2, 3));

    adjList[1].push_back(std::make_pair(0, 2));
    adjList[1].push_back(std::make_pair(5, 1));

    adjList[2].push_back(std::make_pair(0, 3));
    adjList[2].push_back(std::make_pair(5, 2));

    adjList[3].push_back(std::make_pair(1, 4));
    adjList[3].push_back(std::make_pair(4, 1));
    adjList[3].push_back(std::make_pair(6, 2));

    adjList[4].push_back(std::make_pair(3, 1));
    adjList[4].push_back(std::make_pair(5, 2));
    adjList[4].push_back(std::make_pair(6, 1));

    adjList[5].push_back(std::make_pair(1, 1));
    adjList[5].push_back(std::make_pair(2, 2));
    adjList[5].push_back(std::make_pair(4, 2));
    adjList[5].push_back(std::make_pair(6, 2));

    adjList[6].push_back(std::make_pair(3, 2));
    adjList[6].push_back(std::make_pair(4, 1));
    adjList[6].push_back(std::make_pair(5, 2));

}

void DijkstraList::DijkstraSP(int &start) {
    std::cout << "\nGetting the shortest path from " << start << " to all other nodes.\n";


    // Initialize all source->vertex as infinite.
    int n = adjList.size();
    for(int i = 0; i < n; i++)
    {
        dist.push_back(INFINITY); // Define "infinity" as necessary by constraints.
    }

    // Create a PQ.
    std::priority_queue<std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;

    // Add source to pq, where distance is 0.
    pq.push(std::make_pair(start, 0));
    dist[start] = 0;

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
            if(dist[v] > dist[u] + weight)
            {
                // Update the distance of v.
                dist[v] = dist[u] + weight;
                // Insert v into the pq.
                pq.push(std::make_pair(v, dist[v]));
            }
        }
    }



    PrintShortestPath(dist, start);
}

void DijkstraList::PrintShortestPath(std::vector<int> &dist, int &start) {
    std::cout << "\nPrinting the shortest paths for node " << start << ".\n";
    for(int i = 0; i < dist.size(); i++)
    {
        std::cout << "The distance from node " << start << " to node " << i << " is: " << dist[i] << std::endl;
    }
}
