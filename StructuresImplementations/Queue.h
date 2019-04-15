//
// Created by Wojciech Konury on 13/03/2019.
//

#ifndef STRUCTURESIMPLEMENTATIONS_QUEUE_H
#define STRUCTURESIMPLEMENTATIONS_QUEUE_H


#include "Container.h"

template <typename T>
class Queue {
private:
    Container<T> *first;
    Container<T> *last;

public:
    Queue(){
        first = nullptr;
        last = nullptr;
    }

    void enqueue(const T& newElement);
    T dequeue();
};

template<typename T>
void Queue<T>::enqueue(const T &newElement) {
    Container<T>* tmp;
    tmp = new Container<T>(newElement);

    if(first == nullptr){
        first = tmp;
        last = first;
    } else{
        last->nextElement = tmp;
        last = tmp;
    }
}

template<typename T>
T Queue<T>::dequeue() {

    Container<T>* tmp = first;
    first = first->nextElement;

    return tmp->data;
}


#endif //STRUCTURESIMPLEMENTATIONS_QUEUE_H
