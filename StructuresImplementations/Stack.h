//
// Created by Wojciech Konury on 10/03/2019.
//

#ifndef STRUCTURESIMPLEMENTATIONS_STACK_H
#define STRUCTURESIMPLEMENTATIONS_STACK_H




#include "Container.h"
#include "include/catch.hpp"

template <typename T>
class Stack {
private:
    Container<T> *top;

public:
    Stack(){
        top = nullptr;
    }

    void push(const T& newElement);
    T pop();
    T getTop();
};

template<typename T>
void Stack<T>::push(const T &newElement) {
    if(top == nullptr){
        top = new Container<T>(newElement);
    } else{
        Container<T>* tmp;
        tmp = new Container<T>(newElement);

        tmp->nextElement = top;
        top = tmp;
    }
}

template<typename T>
T Stack<T>::pop() {
    if(top == nullptr){
        //TODO zwrocic wyjatek!
    }

    Container<T>* tmp = top;
    top = top->nextElement;

    return tmp->data;
}

template<typename T>
T Stack<T>::getTop() {
    if(top == nullptr){
        //TODO zwrocic wyjatek!
    }
    return top->data;
}

//TEST_CASE("Push() & Pop()", "[Stack]")
//{
//    Stack<int> stack;
//
//    SECTION("add items and get top"){
//        stack.push(61);
//        stack.push(82);
//        stack.push(21);
//
//        REQUIRE(stack.getTop() == 21);
//    }
//}


#endif //STRUCTURESIMPLEMENTATIONS_STACK_H
