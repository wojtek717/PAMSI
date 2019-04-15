//
// Created by Wojciech Konury on 29/03/2019.
//

#include "HeapS.h"

void HeapS::heapify(int *arr, int nSize, int last) {
    int tmp;

    int largestElement = last; //Ostatni element drzewa

    /* Prawa i lewa strona drzewa */
    int leftSide = 2*last + 1;
    int rightSide = 2*last + 2;


    /* Sprawsc poprawnosc ulozenia elementow w drzewie */
    /* Jezeli element po lewej stronie jest wiekszy */
    if (leftSide < nSize && arr[leftSide] > arr[largestElement]){
        largestElement = leftSide;
    }

    /* Jezeli element po prawej jest wiekszy */
    if (rightSide < nSize && arr[rightSide] > arr[largestElement]){
        largestElement = rightSide;
    }

    /* Jezeli najwiekszy element nie jest korzeniem drzewa */
    if (largestElement != last) {
        /* Zamien elementy miejscami */
        tmp = arr[last];
        arr[last] = arr[largestElement];
        arr[largestElement] = tmp;

        heapify(arr, nSize, largestElement);
    }
}

void HeapS::HeapSort(int *arr, u_long size) {
    int tmp;

    /* Od srodka do lewej strony <- */
    for (int i = size / 2 - 1; i >= 0; --i)
        heapify(arr, size, i);

    /* Od konca do srodka <- */
    for (int i = size-1; i>=0; --i)
    {
        tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;


        heapify(arr, i, 0);
    }
}
