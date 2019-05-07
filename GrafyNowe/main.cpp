#include <iostream>
#include <fstream>
#include "MatrixGraph.h"
#include "ListGraph.h"
#include <chrono>

using namespace std::chrono;


struct Mes {
    int verticees;
    int fill;
    double avgTime;
};

bool saveTimeToFile(std::string fileName, std::vector<Mes> &Data){
    std::fstream file;

    file.open(fileName, std::ios::out);

    if (file.good()){
        file << "Vertices;Fill;Avarage Time" << std::endl;

        for (int i = 0; i < Data.size(); ++i) {
            file << Data[i].verticees << ";" << Data[i].fill << ";" << Data[i].avgTime << std::endl;
        }

        return true;
    }

    return false;
}

void MeasureTime(){

    std::vector<int> vertices = {5, 50, 100, 250, 500};
    std::vector<int> fill = {25, 50, 75, 100};

    std::vector<Mes> DijkstraMatrix;
    std::vector<Mes> DijkstraList;
    std::vector<Mes> BellmanMatrix;
    std::vector<Mes> BellmanList;

    double DijkstraMGAvg = 0;
    double DijkstraLGAvg = 0;
    double BellmanMGAvg = 0;
    double BellmanLGAvg = 0;

    Mes mes;

    for (int i = 0; i < vertices.size(); ++i) {
        for (int k = 0; k < fill.size(); ++k) {
            DijkstraMGAvg = 0;
            DijkstraLGAvg = 0;
            BellmanMGAvg = 0;
            BellmanLGAvg = 0;

            for (int j = 0; j < 10; ++j) {
                std::cout << "Vertices: " << vertices[i] << " Fill: " << fill[k] << " #" << j << std::endl;

                ListGraph LG(vertices[i]);
                MatrixGraph MG(vertices[i]);

                //Dijkstra Matrix
                MG.GenerateGraph(false, fill[k]);
                auto start = high_resolution_clock::now();
                MG.Dijkstra(0);
                auto stop = high_resolution_clock::now();
                duration<double> time_span = duration_cast<nanoseconds>(stop - start);
                DijkstraMGAvg = DijkstraMGAvg + time_span.count();

                //Dijkstra List
                LG.GenerateGraph(false, fill[k]);
                start = high_resolution_clock::now();
                LG.Dijkstra(0);
                stop = high_resolution_clock::now();
                time_span = duration_cast<nanoseconds>(stop - start);
                DijkstraLGAvg = DijkstraLGAvg + time_span.count();

                //Bellman Matrix
                MG.GenerateGraph(true, fill[k]);
                start = high_resolution_clock::now();
                MG.BellmanFord(0);
                stop = high_resolution_clock::now();
                time_span = duration_cast<nanoseconds>(stop - start);
                BellmanMGAvg = BellmanMGAvg + time_span.count();

                //Bellman List
                LG.GenerateGraph(true, fill[k]);
                start = high_resolution_clock::now();
                LG.BellmanFord(0);
                stop = high_resolution_clock::now();
                time_span = duration_cast<nanoseconds>(stop - start);
                BellmanLGAvg = BellmanLGAvg + time_span.count();

                mes.verticees = vertices[i];
                mes.fill = fill[k];
            }
            mes.avgTime = DijkstraMGAvg / 10;
            DijkstraMatrix.push_back(mes);

            mes.avgTime = DijkstraLGAvg / 10;
            DijkstraList.push_back(mes);

            mes.avgTime = BellmanMGAvg / 10;
            BellmanMatrix.push_back(mes);

            mes.avgTime = BellmanLGAvg / 10;
            BellmanList.push_back(mes);
        }
    }

    saveTimeToFile("DijkstraMatrix.txt", DijkstraMatrix);
    saveTimeToFile("DijkstraList.txt", DijkstraList);
    saveTimeToFile("BellmanMatrix.txt", BellmanMatrix);
    saveTimeToFile("BellmanList.txt", BellmanList);
}

int main() {

    srand(time( NULL ));

    /*
     * Przykładowe uzycie dla grafu w formie macierzy
     *
    MatrixGraph MG(5);
    MG.GenerateGraph(false, 100);
    MG.PrintGraph();

    MG.BellmanFord(0);
    MG.PrintResoult();

    MG.Dijkstra(0);
    MG.PrintResoult();

    ListGraph LG(5);
    LG.GenerateGraph(false, 100);
    LG.PrintGraph();

    LG.BellmanFord(0);
    LG.PrintResoult();

    LG.Dijkstra(0);
    LG.PrintResoult();
    */

    MeasureTime();



    return 0;
}