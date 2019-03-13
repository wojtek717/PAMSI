#include <iostream>
#include "List.h"
#include "Stack.h"
#include "Queue.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    List<int> list;
    Stack<int> stack;
    Queue<int> queue;

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
    std::cout << stack.getTop();

    std::cout << "#########" << std::endl;
    queue.enqueue(12);
    queue.enqueue(13);
    queue.enqueue(14);

    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    queue.enqueue(99);
    std::cout << queue.dequeue();


    return 0;
}