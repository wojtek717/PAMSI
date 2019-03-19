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

void testMyPriorityQueue(){
    PriorityQueue<int> myPriorityQueue;

    std::cout << "####################" << std::endl;
    std::cout << "Own implementation of PriorityQueue -> enqueue() elements with priority 72(2), 127(2), 61(21), 24(1)" << std::endl;

    myPriorityQueue.enqueue(72, 2);
    myPriorityQueue.enqueue(127, 2);
    myPriorityQueue.enqueue(61, 21);
    myPriorityQueue.enqueue(24, 1);

    std::cout << "Dequeue(), Dequeue()" << std::endl;
    std::cout << myPriorityQueue.dequeue() << std::endl;
    std::cout << myPriorityQueue.dequeue() << std::endl;

}
void testStlPriorityQueue(){
    std::priority_queue<int> stlPriorityQueue;

    std::cout << "####################" << std::endl;
    std::cout << "STL implementation of PriorityQueue -> push() elements with 72, 127, 61, 24" << std::endl;

    stlPriorityQueue.push(72);
    stlPriorityQueue.push(127);
    stlPriorityQueue.push(61);
    stlPriorityQueue.push(24);

    std::cout << "Pop out elements" << std::endl;
    std::cout << stlPriorityQueue.top() << std::endl;
    stlPriorityQueue.pop();
    std::cout << stlPriorityQueue.top() << std::endl;
    stlPriorityQueue.pop();
    std::cout << stlPriorityQueue.top() << std::endl;
    stlPriorityQueue.pop();
}

void testMyMapString(){
    Map<std::string, std::string> myMapString;
    std::string key;
    std::string value;

    std::cout << "####################" << std::endl;
    std::cout << "Own implementation of HashMap - String" << std::endl;

    key = "Marka";
    value = "BMW";
    std::cout << "Insert obiect with key: " + key + " and value: " + value << std::endl;
    myMapString.insert(key, value);
    std::cout << "Get value of obiect with key: " + key + " -> " << myMapString[key]<< std::endl << std::endl;

    key = "Model";
    value = "A4";
    std::cout << "Insert obiect with key: " + key + " and value: " + value << std::endl;
    myMapString.insert(key, value);
    std::cout << "Get value of obiect with key: " + key + " -> " << myMapString[key]<< std::endl << std::endl;

    key = "Silnik";
    value = "Benzyna";
    std::cout << "Insert obiect with key: " + key + " and value: " + value << std::endl;
    myMapString.insert(key, value);
    std::cout << "Get value of obiect with key: " + key + " -> " << myMapString[key]<< std::endl << std::endl;

    key = "Pojemnosc";
    value = "2 litry";
    std::cout << "Insert obiect with key: " + key + " and value: " + value << std::endl;
    myMapString.insert(key, value);
    std::cout << "Get value of obiect with key: " + key + " -> " << myMapString[key]<< std::endl << std::endl;

    key = "Silnik";
    std::cout << "Remove obiect with key: " + key << std::endl;
    myMapString.remove(key);
    std::cout << "Get value of obiect with key: " + key + " -> " << myMapString[key]<< std::endl << std::endl;

}

void testMyMapInt(){
    Map<int, int> myMapInt;
    int key;
    int value;

    std::cout << "####################" << std::endl;
    std::cout << "Own implementation of HashMap - Int" << std::endl;


    key = 1;
    value = 12;
    std::cout << "Insert obiect with key: " << key << " and value: " << value << std::endl;
    myMapInt.insert(key, value);
    std::cout << "Get value of obiect with key: " << key << " -> " << myMapInt[key]<< std::endl << std::endl;

    key = 32;
    value = 102;
    std::cout << "Insert obiect with key: " << key << " and value: " << value << std::endl;
    myMapInt.insert(key, value);
    std::cout << "Get value of obiect with key: " << key << " -> " << myMapInt[key]<< std::endl << std::endl;

    key = 0;
    value = 213;
    std::cout << "Insert obiect with key: " << key << " and value: " << value << std::endl;
    myMapInt.insert(key, value);
    std::cout << "Get value of obiect with key: " << key << " -> " << myMapInt[key]<< std::endl << std::endl;

    key = 32;
    std::cout << "Remove obiect with key: " << key << std::endl;
    myMapInt.remove(key);
    std::cout << "Get value of obiect with key: " << key << " -> " << myMapInt[key]<< std::endl << std::endl;

}



int main() {





// ##### Stack #####
//    testMyList();
//    testStlList();


// ##### Stack #####
//    testMyStack();
//    testStlStack();


// ##### Queue #####
//    testMyQueue();
//    testStlQueue();


// ##### PriorityQueue #####
//    testMyPriorityQueue();
//    testStlPriorityQueue();


// ##### Map #####
//    testMyMapString();
//    testMyMapInt();


    return 0;
}