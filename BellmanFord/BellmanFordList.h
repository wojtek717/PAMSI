//
// Created by Wojciech Konury on 20/04/2019.
//

#ifndef BELLMANFORD_BELLMANFORDLIST_H
#define BELLMANFORD_BELLMANFORDLIST_H


#include <vector>
#include <list>

class BellmanFordList {

public:
    int bellmanFord(
            std::vector< std::list<std::pair<int, int> > > adjacencyList,
            int vertices,
            int startVertex,
            std::vector< std::pair<int, int> > & shortestDistances
    );

};


#endif //BELLMANFORD_BELLMANFORDLIST_H
