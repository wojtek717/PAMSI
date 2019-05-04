#include <iostream>
#include <chrono>
#include <fstream>
#include "DijkstraArray.h"
#include "DijkstraList.h"


#define INFINITY 9999999
using namespace std::chrono;

int main() {
    srand(time( NULL ));
    using namespace std::chrono;


// ####################################################################

    std::vector<int> vertices = {5, 50, 100, 250, 500};
    std::vector<int> fill = {25, 50, 75, 100};

    double arrayAvgTime = 0;
    double listAvgTime = 0;

    std::fstream arrayTimeFile;
    std::fstream listTimeFile;

    std::string arrayTimeFileName = "DArrayTime.txt";
    std::string listTimeFileName = "DListTime.txt";

    arrayTimeFile.open(arrayTimeFileName, std::ios::out);
    listTimeFile.open(listTimeFileName, std::ios::out);

    if (arrayTimeFile.good() && listTimeFile.good()){
        arrayTimeFile << "Vertices;Fill;Avarage Time" << std::endl;
        listTimeFile << "Vertices;Fill;Avarage Time" << std::endl;
    } else{
        std::cout << "CANT OPEN FILE";
        return 101;
    }

    for (int i = 0; i < vertices.size(); ++i) {
        for (int k = 0; k < fill.size(); ++k) {
            arrayAvgTime = 0;
            listAvgTime = 0;

            for (int j = 0; j < 10; ++j) {
                DijkstraArray DA(vertices[i]);
                DijkstraList DL(vertices[i]);

                DA.GenerateGraph(fill[k]);
                DL.GenerateGraph(fill[k]);

                //Array
                auto start = high_resolution_clock::now();
                DA.ExecuteAlghoritm(0);
                auto stop = high_resolution_clock::now();
                duration<double> time_span = duration_cast<nanoseconds>(stop - start);
                arrayAvgTime = arrayAvgTime + time_span.count();

                //List
                start = high_resolution_clock::now();
                DL.ExecuteAlgorithm(0);
                stop = high_resolution_clock::now();
                time_span = duration_cast<nanoseconds>(stop - start);
                listAvgTime = listAvgTime + time_span.count();

                std::cout << "Vertices: " << vertices[i] << " Fill: " << fill[k] << " #" << j << std::endl;
            }
            arrayAvgTime = arrayAvgTime / 10;
            listAvgTime = listAvgTime / 10;

            arrayTimeFile << vertices[i] << ";" << fill[k] << ";" << arrayAvgTime << std::endl;
            listTimeFile << vertices[i] << ";" << fill[k] << ";" << listAvgTime << std::endl;
        }
    }

    return 0;
}