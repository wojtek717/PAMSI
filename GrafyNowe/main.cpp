#include <iostream>
#include "MatrixGraph.h"
#include "ListGraph.h"

int main() {

    srand(time( NULL ));

    // Przykładowe uzycie dla grafu w formie macierzy
//    MatrixGraph MG(5);
//    MG.GenerateGraph(false, 100);
//    MG.PrintGraph();
//
//    MG.BellmanFord(0);
//    MG.PrintResoult();
//
//    MG.Dijkstra(0);
//    MG.PrintResoult();

    ListGraph LG(5);
    LG.GenerateGraph(false, 100);
    LG.PrintGraph();

    LG.BellmanFord(0);
    LG.PrintResoult();

    LG.Dijkstra(0);
    LG.PrintResoult();



    return 0;
}