#include <iostream>
#include "List.h"
#include "Stack.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    List<int> list;
    Stack<int> stack;

    list.pushBack(1);   //0
    list.pushBack(2);   //1
    list.pushBack(3);   //2
    list.pushBack(4);   //3
    list.pushBack(5);   //4
    list.pushBack(2);

    //list.remove(2);

    std::cout << list[2] << std::endl;

    //list.insert(99, 3);

    stack.push(11);
    stack.push(12);
    stack.push(13);
    std::cout <<  stack.pop();


    return 0;
}