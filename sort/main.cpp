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

//        std::cout << arr[i] << std::endl;
    }

    std::cout << "###############" << std::endl << std::endl;
}

void FillArrayWithSortedNumbers(int *arr, u_long size){
    for (int i = 0; i < size; ++i){
        arr[i] = i + 1;
    }
}

void FillArrayWithSameNumbers(int *arr, u_long size){
    int numb = rand();

    for (int i = 0; i < size; ++i) {
        arr[i] = numb;
    }
}

int main() {
    srand( time( NULL ) );

    Bubble bubble;
    MergeS merge;
    HeapS heap;

    std::fstream bubbleFile;
    std::fstream mergeFile;
    std::fstream heapFile;

    std::string bubbleFileName = "BubbleData.txt";
    std::string mergeFileName = "MergeData.txt";
    std::string heapFileName = "HeapData.txt";

    bubbleFile.open(bubbleFileName, std::ios::out);
    mergeFile.open(mergeFileName, std::ios::out);
    heapFile.open(heapFileName, std::ios::out);

    if (bubbleFile.good()){
        bubbleFile << "Size;Avarage Time" << std::endl;

    } else{
        std::cout << "CANT OPEN FILE";
        return 101;
    }

    if (mergeFile.good()){
        mergeFile << "Size;Avarage Time" << std::endl;

    } else{
        std::cout << "CANT OPEN FILE";
        return 101;
    }

    if (heapFile.good()){
        heapFile << "Size;Avarage Time" << std::endl;

    } else{
        std::cout << "CANT OPEN FILE";
        return 101;
    }


    double bubbleAvgTime = 0;
    double mergeAvgTime = 0;
    double heapAvgTime = 0;
    u_long size = 10;

    while (size <= 100){

        /* Stworz tablice o odpowiedniej wielkosci */
        int* barray = new int[size];
        int* marray = new int[size];
        int* harray = new int[size];

        bubbleAvgTime = 0;
        mergeAvgTime = 0;
        heapAvgTime = 0;

        for (int j = 0; j < 10; ++j) {
            FillArrayWithRandomNumbers(barray, size, 1, 100);
            FillArrayWithRandomNumbers(marray, size, 1, 100);
            FillArrayWithRandomNumbers(harray, size, 1, 100);

//            FillArrayWithSortedNumbers(barray, size);
//            FillArrayWithSortedNumbers(marray, size);
//            FillArrayWithSortedNumbers(harray, size);

            /* Bubble sort */
            std::cout << "Sortuje metoda bubblesort tablice o rozmiarze: " << size << std::endl;
            auto start = high_resolution_clock::now();
            if(size <= 100000){
                bubble.Sort(barray, size);
            }
            auto stop = high_resolution_clock::now();

            duration<double> time_span = duration_cast<nanoseconds>(stop - start);
            bubbleAvgTime = bubbleAvgTime + time_span.count();

            PrintArray(barray, size);


            /* Merge sort */
            std::cout << "Sortuje metoda mergeSort tablice o rozmiarze: " << size << std::endl;
            start = high_resolution_clock::now();
            merge.MergeSort(marray, 0, size-1);
            stop = high_resolution_clock::now();

            time_span = duration_cast<nanoseconds>(stop - start);
            mergeAvgTime = mergeAvgTime + time_span.count();


            /* Heap sort */
            std::cout << "Sortuje metoda heapSort tablice o rozmiarze: " << size << std::endl;
            start = high_resolution_clock::now();
            heap.HeapSort(harray, size);
            stop = high_resolution_clock::now();

            time_span = duration_cast<nanoseconds>(stop - start);
            heapAvgTime = heapAvgTime + time_span.count();

        }

        bubbleAvgTime = bubbleAvgTime / 10;
        mergeAvgTime = mergeAvgTime / 10;
        heapAvgTime = heapAvgTime / 10;

        if(bubbleFile.good()){
            bubbleFile << size << ";" << bubbleAvgTime << std::endl;
        } else{
            std::cout << "Cant open ";
        }

        if(mergeFile.good()){
            mergeFile << size << ";" << mergeAvgTime << std::endl;
        } else{
            std::cout << "Cant open ";
        }

        if(heapFile.good()){
            heapFile << size << ";" << heapAvgTime << std::endl;
        } else{
            std::cout << "Cant open ";
        }

        size = size * 10;
    }


    return 0;
}

