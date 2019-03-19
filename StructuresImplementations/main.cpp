#include <iostream>
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "Map.h"
#include <list>
#include <stack>
#include <queue>

#include "include/catch.hpp"
//#define CATCH_CONFIG_RUNNER

void testMyList(){
    List<int> myList;

    std::cout << "####################" << std::endl;
    std::cout << "Own implementation of List -> pushBack() elements 20, 93, 12, 40, 12" << std::endl;

    myList.pushBack(20);
    myList.pushBack(93);
    myList.pushBack(12);
    myList.pushBack(40);
    myList.pushBack(12);


    for(auto v : myList){
        std::cout << v << std::endl;
    }

    std::cout << "pushFront() elements 1, 1, 99" << std::endl;

    myList.pushFront(1);
    myList.pushFront(1);
    myList.pushFront(99);

    for(auto v : myList){
        std::cout << v << std::endl;
    }

    std::cout << "Remove() elements 1, 12, 99" << std::endl;

    myList.remove(1);
    myList.remove(12);
    myList.remove(99);

    for(auto v : myList){
        std::cout << v << std::endl;
    }

    std::cout << "Insert element 2 at index 0, insert element 77 at index 2" << std::endl;

    myList.insert(2, 0);
    myList.insert(77, 2);

    for(auto v : myList){
        std::cout << v << std::endl;
    }
}
void testStlList(){
    std::list<int> stlList;
    std::list<int>::iterator it;

    it = stlList.begin();

    std::cout << "####################" << std::endl;
    std::cout << "STL implementation of List -> pushBack() elements 20, 93, 12, 40, 12" << std::endl;

    stlList.push_back(20);
    stlList.push_back(93);
    stlList.push_back(12);
    stlList.push_back(40);
    stlList.push_back(12);



    for(auto v : stlList){
        std::cout << v << std::endl;
    }

    std::cout << "pushFront() elements 1, 1, 99" << std::endl;

    stlList.push_front(1);
    stlList.push_front(1);
    stlList.push_front(99);

    for(auto v : stlList){
        std::cout << v << std::endl;
    }

    std::cout << "Remove() elements 1, 12, 99" << std::endl;

    stlList.remove(1);
    stlList.remove(12);
    stlList.remove(99);

    for(auto v : stlList){
        std::cout << v << std::endl;
    }

    std::cout << "Insert element 2 at index 0, insert element 77 at index 2" << std::endl;

    stlList.insert(it, 2);

    for (int i = 0; i < 2; ++i) {
        it++;
    }

    stlList.insert(it, 77);


    for(auto v : stlList){
        std::cout << v << std::endl;
    }
}

void testMyStack(){
    Stack<int> myStack;

    std::cout << "####################" << std::endl;
    std::cout << "Own implementation of Stack -> push() elements 1, 72, 999" << std::endl;

    myStack.push(1);
    myStack.push(72);
    myStack.push(999);

    std::cout << "GetTop()" << std::endl;

    std::cout << myStack.getTop() << std::endl;

    std::cout << "Pop(), Pop()" <<  std::endl;

    std::cout << myStack.pop() << std::endl;
    std::cout << myStack.pop() << std::endl;

    std::cout << "GetTop()" << std::endl;

    std::cout << myStack.getTop() << std::endl;


}
void testStlStack(){
    std::stack<int> stlStack;

    std::cout << "####################" << std::endl;
    std::cout << "Own implementation of Stack -> push() elements 1, 72, 999" << std::endl;

    stlStack.push(1);
    stlStack.push(72);
    stlStack.push(999);

    std::cout << "top()" << std::endl;

    std::cout << stlStack.top() << std::endl;

    std::cout << "Pop() & top(), Pop() & top() -> because pop() returns void" <<  std::endl;

    stlStack.pop();
    std::cout << stlStack.top() << std::endl;
    stlStack.pop();
    std::cout << stlStack.top() << std::endl;

    std::cout << "GetTop()" << std::endl;

    std::cout << stlStack.top() << std::endl;
}

void testMyQueue(){
    Queue<int> myQueue;

    std::cout << "####################" << std::endl;
    std::cout << "Own implementation of Queue -> enqueue() elements 31, 29, 11" << std::endl;

    myQueue.enqueue(31);
    myQueue.enqueue(29);
    myQueue.enqueue(11);

    std::cout << "Dequeue(), Dequeue()" << std::endl;
    std::cout << myQueue.dequeue() << std::endl;
    std::cout << myQueue.dequeue() << std::endl;

    std::cout << "enqueue(8371), Dequeue()" << std::endl;
    myQueue.enqueue(8371);
    std::cout << myQueue.dequeue() << std::endl;
}
void testStlQueue(){
    std::queue<int> stlQueue;

    std::cout << "####################" << std::endl;
    std::cout << "STL implementation of Queue -> push() elements 31, 29, 11" << std::endl;

    stlQueue.push(31);
    stlQueue.push(29);
    stlQueue.push(11);

    std::cout << "front() & pop(), front() & pop() -> because pop returns void" << std::endl;


    std::cout << stlQueue.front() << std::endl;
    stlQueue.pop();
    std::cout << stlQueue.front() << std::endl;
    stlQueue.pop();

    std::cout << "push(8371), front() & pop()" << std::endl;
    stlQueue.push(8371);
    std::cout << stlQueue.front() << std::endl;
    stlQueue.pop();
}



int main() {


    PriorityQueue<int> myPriorityQueue;
    Map<std::string, std::string> myMapString;
    Map<int, int> myMapInt;




// ##### Stack #####
//    testMyList();
//    testStlList();


// ##### Stack #####
//    testMyStack();
//    testStlStack();


// ##### Queue #####
//    testMyQueue();
//    testStlQueue();





    return 0;
}