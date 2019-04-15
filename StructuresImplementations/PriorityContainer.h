//
// Created by Wojciech Konury on 14/03/2019.
//

#ifndef STRUCTURESIMPLEMENTATIONS_PRIORITYCONTAINER_H
#define STRUCTURESIMPLEMENTATIONS_PRIORITYCONTAINER_H


template <typename T>
struct PriorityContainer {
    int priority;
    T data;
    PriorityContainer* nextElement;

public:
    PriorityContainer(){}

    PriorityContainer(T element, int priority){
        this->priority = priority;
        data = element;
        nextElement = nullptr;
    }
};


#endif //STRUCTURESIMPLEMENTATIONS_PRIORITYCONTAINER_H
