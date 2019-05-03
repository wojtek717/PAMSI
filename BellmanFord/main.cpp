#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include "BellmanFordArray.h"
#include "BellmanFordList.h"




int main() {
    srand( time( NULL ) );

    BellmanFordArray bfA(10);
    BellmanFordList bfL(5);




//    bfA.GenerateGraph(100);
//    bfA.ExecuteAlghoritm(0);
//    bfA.PrintOutput("BellmanArrayOutputFile.txt");



    bfL.GenerateGraph(50);
    bfL.ExecuteAlgorithm(0);
    bfL.PrintOutput("BellmanListOutputFile.txt");


    std::fstream BellmanArrayFille;
    std::fstream BellmanListFille;


    std::string BellmanArrayFilleName = "BellmanArrayTime.txt";
    std::string BellmanListFilleName = "BellmanListTime.txt";


    BellmanArrayFille.open(BellmanArrayFilleName, std::ios::out);
    BellmanListFille.open(BellmanListFilleName, std::ios::out);






    return 0;
}