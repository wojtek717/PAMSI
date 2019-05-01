#include <iostream>
#include <vector>
#include "BellmanFordArray.h"


#define INFINITY 9999999

int main() {

    BellmanFordArray bfA(7);


    std::vector<std::vector<int>> graph = {
            {0, 6, 5, 5, 0, 0, 0},
            {0, 0, 0, 0, -1, 0, 0},
            {0, -2, 0, 0, 1, 0, 0},
            {0, 0, -2, 0, 0, -1, 0},
            {0, 0, 0, 0, 0, 0, 3},
            {0, 0, 0, 0, 0, 0, 3},
            {0, 0, 0, 0, 0, 0, 0}
    };

    bfA.ExecuteAlghoritm(graph, 0);
    bfA.PrintOutput();




    return 0;
}