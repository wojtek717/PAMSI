//
// Created by Wojciech Konury on 01/05/2019.
//

#include "BellmanFordArray.h"
#include "Edge.h"

BellmanFordArray::BellmanFordArray(int verticesAmount) {
    this->verticesAmount = verticesAmount;
    isNegativeCircle = false;

    std::vector<int> vector;

    for (int i = 0; i < verticesAmount; ++i) {
        graph.push_back(vector);
        for (int k = 0; k < verticesAmount; ++k) {
            graph[i].push_back(0);
        }
    }
}

void BellmanFordArray::ExecuteAlghoritm(int start) {
    Vertex vertex;
//    Edge edge;
//    std::vector<Edge> edges;


    // Zainicjalizuj wszystkie odleglosci jako inf
    for (int i = 0; i < verticesAmount; i++){
        vertex.index = i;
        vertices.push_back(vertex);
    }

    //Odleglosc startu do startu to zawsze 0
    vertices[start].distance = 0;

//    for (int j = 0; j < verticesAmount; ++j) {
//        for (int i = 0; i < verticesAmount; ++i) {
//            if (graph[j][i] != 0){
//                edge.startIndex = j;
//                edge.endIndex = i;
//                edge.distance = graph[j][i];
//
//                edges.push_back(edge);
//            }
//        }
//    }
//
//    for (int i = 0; i < (verticesAmount - 1); ++i) {
//        for (int k = 0; k < edges.size(); ++k){
//            if(vertices[edges[k].endIndex].distance > vertices[edges[k].startIndex].distance + edges[k].distance){
//                vertices[edges[k].endIndex].distance = vertices[edges[k].startIndex].distance + edges[k].distance;
//                vertices[edges[k].endIndex].parent = &vertices[edges[k].startIndex];
//            }
//        }
//    }

//    for (int k = 0; k < edges.size(); ++k){
//        if(vertices[edges[k].endIndex].distance > vertices[edges[k].startIndex].distance + edges[k].distance){
//            isNegativeCircle = true;
//            break;
//        }
//    }



    for (int k = 0; k < (verticesAmount - 1); ++k) {
        for (int i = 0; i < verticesAmount; ++i) {
            for (int j = 0; j < verticesAmount; ++j) {
                if (graph[i][j] != 0){
                    if(vertices[j].distance > vertices[i].distance + graph[i][j]){
                        vertices[j].distance = vertices[i].distance + graph[i][j];
                        vertices[j].parent = &vertices[i];
                    }
                }
            }
        }
    }

    for (int j = 0; j < verticesAmount; ++j) {
        for (int i = 0; i < verticesAmount; ++i) {
            if (graph[i][j] != 0){
                if(vertices[j].distance > vertices[i].distance + graph[i][j]){
                    isNegativeCircle = true;
                    break;
                }
            }
        }
    }



}

void BellmanFordArray::PrintOutput(std::string fileName) {
    if(isNegativeCircle){
        std::cout << "NEGATIVE CIRCLE!" << std::endl;
    }

    std::cout << "Vertex --- Distance from start" << std::endl;

    for (int i = 0; i < verticesAmount; ++i) {
        std::cout << "(" << i << ") --- " << vertices[i].distance << std::endl;
    }

    std::cout << "Graph:" << std::endl;
    for (int i = 0; i < verticesAmount; ++i) {
        for (int j = 0; j < verticesAmount; ++j) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }





    //##

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

        if(isNegativeCircle){
            outputFile << "NEGATIVE CIRCLE!" << std::endl;
        }

        outputFile << "Vertex --- Distance from start --- Path" << std::endl;
        for (int j = 0; j < verticesAmount; ++j) {
            outputFile << "(" << vertices[j].index << ")" << " --- " << vertices[j].distance << " --- ";



            if(!isNegativeCircle){
                Vertex *parent = vertices[j].parent;
                while (parent != nullptr){
                    outputFile << " -> (" << parent->index << ")";
                    parent = parent->parent;
                }
            }

            outputFile << std::endl;
        }

        outputFile.close();
    }
}

void BellmanFordArray::AddEdge(Edge edge) {
    graph[edge.startIndex][edge.endIndex] = edge.distance;
}

void BellmanFordArray::GenerateGraph(int fill) {
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

                if((rand() % 100) > 5){
                    edge.distance = rand() % 1000;
                } else{
                    edge.distance = (rand() % 5) * -1;
                }

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
