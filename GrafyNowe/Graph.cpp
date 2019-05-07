//
// Created by Wojciech Konury on 07/05/2019.
//

#include "Graph.h"

Graph::Graph() {}

void Graph::GenerateGraph(bool negative, int fill) {
    Edge edge;
    std::vector<Edge> edgeList;

    if (fill > 100) {
        fill = 100;
    }
    if (fill < 0) {
        fill = 0;
    }

    int maxEdges = verticesAmomunt * (verticesAmomunt - 1);
    int edgesLeft = (maxEdges * fill) / 100;
    int randIndex;

    this->isNegativeCircle = false;

    for (int i = 0; i < verticesAmomunt; ++i) {

        for (int k = 0; k < verticesAmomunt; ++k) {

            if (i != k) {
                edge.startIndex = i;
                edge.endIndex = k;

                if (negative) {
                    if ((rand() % 100) > 5) {
                        edge.distance = rand() % 1000;
                    } else {
                        edge.distance = (rand() % 5) * -1;
                    }
                } else {

                    edge.startIndex = i;
                    edge.endIndex = k;
                    edge.distance = rand() % 1000;
                }
                edgeList.push_back(edge);
            }
        }
    }

    while (edgesLeft > 0) {
        randIndex = rand() % edgeList.size();

        addEdge(edgeList[randIndex]);
        edgeList.erase(edgeList.begin() + randIndex);

        edgesLeft--;
    }
}
