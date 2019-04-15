//
// Created by Wojciech Konury on 29/03/2019.
//

#ifndef SORT_MERGES_H
#define SORT_MERGES_H


class MergeS {
private:
    void merge(int *array, int low, int high, int mid);

public:
    void MergeSort(int *array, int low, int high);
};


#endif //SORT_MERGES_H
