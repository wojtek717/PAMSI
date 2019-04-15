#include <utility>

//
// Created by Wojciech Konury on 28/03/2019.
//

#include "Bubble.h"



void Bubble::Sort(int *array, u_long size) {
    int tmp;
    bool swapped = false;

    for( int i = 0; i < size; i++ )
    {
        for( int j = 0; j < size - 1; j++ )
        {
            if( array[j] > array[j + 1] ){
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}
