#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include "Bubble.h"
#include "MergeS.h"
#include "HeapS.h"

using namespace std::chrono;

void PrintArray(int *arr, u_long size){
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << std::endl;
    }
}

void FillArrayWithRandomNumbers(int *arr, u_long size, int down, int up){
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % (up - down) + down;

        std::cout << arr[i] << std::endl;
    }

    std::cout << "###############" << std::endl << std::endl;
}

int main() {
    Bubble bubble;
    MergeS merge;
    HeapS heap;

    std::fstream plik;
    std::string name = "TimesData.txt";

    plik.open(name, std::ios::out);

    if (plik.good()){
        plik << "Size;Avarage Time" << std::endl;
    } else{
        std::cout << "CANT OPEN FILE";
        return 101;
    }

    double avgTime = 0;
    u_long size = 10;



    while (size <= 1000){
        int* array = new int[size];
        avgTime = 0;

        for (int j = 0; j < 10; ++j) {
            FillArrayWithRandomNumbers(array, size, 1, 100);

            auto start = high_resolution_clock::now();
            //merge.MergeSort(array, 0, size-1);
            //bubble.Sort(array, size);
            heap.HeapSort(array, size);
            auto stop = high_resolution_clock::now();

            duration<double> time_span = duration_cast<nanoseconds>(stop - start);
            avgTime = avgTime + time_span.count();

            std::cout << std::endl <<"Time taken by function: "
                      << time_span.count() << " seconds" << std::endl;

            std::cout << "*************" << std::endl << std::endl;
        }

        avgTime = avgTime / 10;

        if(plik.good()){
            plik << size << ";" << avgTime << std::endl;
        } else{
            std::cout << "Cant open ";
        }





        size = size * 10;
    }


    return 0;
}

