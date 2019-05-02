#include <iostream>
#include <vector>
#include "BellmanFordArray.h"
#include "BellmanFordList.h"


#define INFINITY 9999999

int main() {

    BellmanFordArray bfA(7);
    BellmanFordArray bfA2(4);

    BellmanFordList bfL(7);


    std::vector<std::vector<int>> graph = {
            {0, 6, 5, 5, 0, 0, 0},
            {0, 0, 0, 0, -1, 0, 0},
            {0, -2, 0, 0, 1, 0, 0},
            {0, 0, -2, 0, 0, -1, 0},
            {0, 0, 0, 0, 0, 0, 3},
            {0, 0, 0, 0, 0, 0, 3},
            {0, 0, 0, 0, 0, 0, 0}
    };

    std::vector<std::vector<int>> graph2 = {
            {0, 4, 0, 5},
            {0, 0, 0, 0},
            {0, -10, 0, 0},
            {0, 0, 3, 0}
    };

    std::vector<std::vector<int>> graph3 = {
            {0, 1, 0, 0},
            {0, 0, -1, 0},
            {0, 0, 0, -1},
            {-1, 0, 0, 0}
    };

    bfL.AddEdge(0, 1, 6);
    bfL.AddEdge(0, 2, 5);
    bfL.AddEdge(0, 3, 5);
    bfL.AddEdge(1, 4, -1);
    bfL.AddEdge(2, 1, -2);
    bfL.AddEdge(2, 4, 1);
    bfL.AddEdge(3, 2, -2);
    bfL.AddEdge(3, 5, -1);
    bfL.AddEdge(4, 6, 3);
    bfL.AddEdge(5, 6, 3);



//    bfA.ExecuteAlghoritm(graph, 0);
//    bfA.PrintOutput();

//    std::cout << "#####" << std::endl;
//    bfA2.ExecuteAlghoritm(graph3, 0);
//    bfA2.PrintOutput();

    bfL.ExecuteAlgorithm(0);
    bfL.PrintOutput();






    return 0;
}