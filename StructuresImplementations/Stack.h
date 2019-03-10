//
// Created by Wojciech Konury on 10/03/2019.
//

#ifndef STRUCTURESIMPLEMENTATIONS_STACK_H
#define STRUCTURESIMPLEMENTATIONS_STACK_H


#include "Container.h"

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


#endif //STRUCTURESIMPLEMENTATIONS_STACK_H
