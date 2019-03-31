//
// Created by Wojciech Konury on 29/03/2019.
//

#ifndef SORT_HEAPS_H
#define SORT_HEAPS_H


#include <zconf.h>

class HeapS {
private:
    void heapify(int arr[], int nSize, int last);

public:
    void HeapSort(int arr[], u_long size);

};


#endif //SORT_HEAPS_H
