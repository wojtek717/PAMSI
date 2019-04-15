//
// Created by Wojciech Konury on 14/03/2019.
//

#ifndef STRUCTURESIMPLEMENTATIONS_PRIORITYQUEUE_H
#define STRUCTURESIMPLEMENTATIONS_PRIORITYQUEUE_H

#include "PriorityContainer.h"

template <typename T>
class PriorityQueue {
private:
    PriorityContainer<T> *first;
    PriorityContainer<T> *last;

public:
    PriorityQueue(){
        first = nullptr;
        last = nullptr;
    }

    void enqueue(const T& newElement, int priority);
    T dequeue();
};

template<typename T>
void PriorityQueue<T>::enqueue(const T &newElement, int priority) {
    PriorityContainer<T>* tmp;
    tmp = new PriorityContainer<T>(newElement, priority);

    if(first == nullptr){
        first = tmp;
        last = first;
    } else{
        PriorityContainer<T>* queueElement = first;

        //find last element with this priority value or lower
        while (tmp->priority < queueElement->priority){

            queueElement = queueElement->nextElement;

            if(queueElement->nextElement == nullptr){
                last->nextElement = tmp;
                last = tmp;

                return;
            }
        }

          if(queueElement == first){
            tmp->nextElement = first;
            first = tmp;
        } else{

            tmp->nextElement = queueElement->nextElement;
            queueElement->nextElement = tmp;
        }
    }
}

template<typename T>
T PriorityQueue<T>::dequeue() {
    PriorityContainer<T>* tmp = first;
    first = first->nextElement;

    return tmp->data;
}





#endif //STRUCTURESIMPLEMENTATIONS_PRIORITYQUEUE_H
