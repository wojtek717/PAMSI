#include <iostream>
#include "Liczba.h"

int main() {

    Liczba *l1 = new Liczba();
    l1->liczba = 10;

    Liczba *l2 = new Liczba();
    l2->liczba = 20;

    l2 = l1;
    l2->liczba = 99;

    std::cout << l1->liczba << std::endl;
    std::cout << l2->liczba;

    return 0;
}