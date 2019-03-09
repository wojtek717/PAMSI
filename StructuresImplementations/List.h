//
// Created by Wojciech Konury on 09/03/2019.
//

#ifndef STRUCTURESIMPLEMENTATIONS_LIST_H
#define STRUCTURESIMPLEMENTATIONS_LIST_H


#include "ListElement.h"

template <typename T>
class List {
private:
    ListElement<T> *head;
    ListElement<T> *tail;

public:
    List(){
        head = nullptr;
        tail = nullptr;
    }

    void pushBack(const T& newElement);
    void pushFront(const T& newElement);

};

template<typename T>
void List<T>::pushBack(const T &newElement) {
    if(head == nullptr){
        head = new ListElement<T>(newElement);
        tail = head;
    } else{
        ListElement<T>* tmp;
        tmp = new ListElement<T>(newElement);
        tail->nextElement = tmp;
        tail = tmp;
        tail->nextElement = nullptr;
    }
}

template<typename T>
void List<T>::pushFront(const T &newElement) {

}


#endif //STRUCTURESIMPLEMENTATIONS_LIST_H
