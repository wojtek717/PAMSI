#include <iostream>
#include <vector>
#include "Bubble.h"


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

    u_long size = 100;
    int array[size];
    FillArrayWithRandomNumbers(array, size, 10, 50);

    Bubble bubble;
    bubble.Sort(array, size);
    PrintArray(array, size);




//
//    for (int i = 0; i < 1000; ++i) {
//        std::cout << array[i] << std::endl;
//    }


    return 0;
}

