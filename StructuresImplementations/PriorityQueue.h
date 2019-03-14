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
};

template<typename T>
void PriorityQueue<T>::enqueue(const T &newElement, int priority) {
    PriorityContainer<T>* tmp;
    tmp = new PriorityContainer<T>(newElement, priority);

    if(first == nullptr){
        first = tmp;
        last = first;
    } else{
        //find last element with this priority value or higher
        PriorityContainer<T>* queueElement = first;

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


#endif //STRUCTURESIMPLEMENTATIONS_PRIORITYQUEUE_H
