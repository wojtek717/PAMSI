#include <iostream>
#include "List.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    List<int> list;

    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);


    return 0;
}