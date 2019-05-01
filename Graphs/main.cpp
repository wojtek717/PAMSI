#include <iostream>
#include "DijkstraArray.h"
#include "DijkstraList.h"


#define INFINITY 9999999

int main() {

//    DijkstraArray diA(9);
////
////
////    std::vector<std::vector<int>> graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
////                                           {4, 0, 8, 0, 0, 0, 0, 11, 0},
////                                           {0, 8, 0, 7, 0, 4, 0, 0, 2},
////                                           {0, 0, 7, 0, 9, 14, 0, 0, 0},
////                                           {0, 0, 0, 9, 0, 10, 0, 0, 0},
////                                           {0, 0, 4, 14, 10, 0, 2, 0, 0},
////                                           {0, 0, 0, 0, 0, 2, 0, 1, 6},
////                                           {8, 11, 0, 0, 0, 0, 1, 0, 7},
////                                           {0, 0, 2, 0, 0, 0, 6, 7, 0}
////    };
////
////    diA.ExecuteAlghoritm(graph, 0);

    DijkstraList diL;
    diL.FormAdjList("EdgeData.txt");

    int start = 0;
    diL.DijkstraSP(start);




    return 0;
}