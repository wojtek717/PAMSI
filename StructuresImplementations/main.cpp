#include <iostream>
#include "List.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    List<int> list;

    list.pushBack(1);   //0
    list.pushBack(2);   //1
    list.pushBack(3);   //2
    list.pushBack(4);   //3
    list.pushBack(5);   //4
    list.pushBack(2);

    //list.remove(2);

    std::cout << list[6];
    std::cout << "dasdas";

    //list.insert(99, 3);


    return 0;
}