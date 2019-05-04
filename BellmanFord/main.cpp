#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include "BellmanFordArray.h"
#include "BellmanFordList.h"

using namespace std::chrono;


int main() {
    srand( time( NULL ) );


    // ####################################################################

    std::vector<int> vertices = {5, 50, 100, 250, 500};
    std::vector<int> fill = {25, 50, 75, 100};

    double arrayAvgTime = 0;
    double listAvgTime = 0;

    std::fstream BellmanArrayFille;
    std::fstream BellmanListFille;

    std::string BellmanArrayFilleName = "BellmanArrayTime.txt";
    std::string BellmanListFilleName = "BellmanListTime.txt";

    BellmanArrayFille.open(BellmanArrayFilleName, std::ios::out);
    BellmanListFille.open(BellmanListFilleName, std::ios::out);

    if (BellmanArrayFille.good() && BellmanListFille.good()){
        BellmanArrayFille << "Vertices;Fill;Avarage Time" << std::endl;
        BellmanListFille << "Vertices;Fill;Avarage Time" << std::endl;
    } else{
        std::cout << "CANT OPEN FILE";
        return 101;
    }

    for (int i = 0; i < vertices.size(); ++i) {
        for (int k = 0; k < fill.size(); ++k) {
            arrayAvgTime = 0;
            listAvgTime = 0;

            for (int j = 0; j < 10; ++j) {
                BellmanFordArray BA(vertices[i]);
                BellmanFordList BL(vertices[i]);

                BA.GenerateGraph(fill[k]);
                BL.GenerateGraph(fill[k]);

                //Array
                auto start = high_resolution_clock::now();
                BA.ExecuteAlghoritm(0);
                auto stop = high_resolution_clock::now();
                duration<double> time_span = duration_cast<nanoseconds>(stop - start);
                arrayAvgTime = arrayAvgTime + time_span.count();

                //List
                start = high_resolution_clock::now();
                BL.ExecuteAlgorithm(0);
                stop = high_resolution_clock::now();
                time_span = duration_cast<nanoseconds>(stop - start);
                listAvgTime = listAvgTime + time_span.count();

                std::cout << "Vertices: " << vertices[i] << " Fill: " << fill[k] << " #" << j << std::endl;
            }
            arrayAvgTime = arrayAvgTime / 10;
            listAvgTime = listAvgTime / 10;

            BellmanArrayFille << vertices[i] << ";" << fill[k] << ";" << arrayAvgTime << std::endl;
            BellmanListFille << vertices[i] << ";" << fill[k] << ";" << listAvgTime << std::endl;
        }
    }




    return 0;
}