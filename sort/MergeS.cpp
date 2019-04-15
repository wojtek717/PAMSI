//
// Created by Wojciech Konury on 29/03/2019.
//

#include "MergeS.h"

/* Polacz dwie czesci
 * *array - Podana tablica do posortowania
 * low - Pierwszy indeks podzielonej czesci do polaczenia
 * high - Ostatni indeks podzielonej czesci do polaczenia
 * mid - Ostatni indeks podzielonej czesci pierwszej polowki do polaczenia
*/
void MergeS::merge(int *array, int low, int high, int mid) {

    int i = low; //Pierwszy indeks elementu podzielonej czesci
    int j = mid + 1; //Pierwszy indeks elementu podzielonej czesci drugiej polowki
    int k = 0;
    int tmp[high-low+1]; //Tablica pomocnicza

    // Odpowiednio laczymy dwie czesci w jedna (tmp[])
    while (i <= mid && j <= high) { //Dlugosc jednej polowki
        if (array[i] < array[j]) {
            tmp[k] = array[i];
            ++k;
            ++i;
        } else {
            tmp[k] = array[j];
            ++k;
            ++j;
        }
    }

    // Wstaw pozostale elementy pierwszej polowki
    while (i <= mid) {
        tmp[k] = array[i];
        ++k;
        ++i;
    }

    // Wstaw pozostale elementy drugiej polowki
    while (j <= high) {
        tmp[k] = array[j];
        ++k;
        ++j;
    }

    // Przypisz posortowane elementy do podanej tablicy
    for (i = low; i <= high; ++i) {
        array[i] = tmp[i-low];
    }
}

/* Posortuj podana tablice
 * *array - podana tablica do posortowania
 * low - pierwszy indeks danej czesci
 * high - ostatni indeks danej czesci
*/
void MergeS::MergeSort(int *array, int low, int high) {
    int mid;

    if (low < high) {
        mid=(low+high)/2;

        // Dziel tablice na 2 do uzyskania pojedynczego elementu
        MergeSort(array, low, mid);
        MergeSort(array, mid+1, high);

        // Polacz podzielone czesci w odpowiedni sposob
        merge(array, low, high, mid);
    }
}
