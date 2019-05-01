#include <iostream>
#include <vector>
#include "BellmanFordArray.h"


#define INFINITY 9999999

int main() {

    BellmanFordArray bfA(7);
    BellmanFordArray bfA2(4);


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



//    bfA.ExecuteAlghoritm(graph, 0);
//    bfA.PrintOutput();

    std::cout << "#####" << std::endl;
    bfA2.ExecuteAlghoritm(graph3, 0);
    bfA2.PrintOutput();






    return 0;
}