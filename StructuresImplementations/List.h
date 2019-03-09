//
// Created by Wojciech Konury on 09/03/2019.
//

#ifndef STRUCTURESIMPLEMENTATIONS_LIST_H
#define STRUCTURESIMPLEMENTATIONS_LIST_H

#include <iostream>
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
    void insert(const T& newElement , int index);

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
    if(head == nullptr){
        head = new ListElement<T>(newElement);
        tail = head;
    } else{
        ListElement<T>* tmp;
        tmp = new ListElement<T>(newElement);

        tmp->nextElement = head;
        head = tmp;
    }
}

template<typename T>
void List<T>::insert(const T &newElement, int index) {
    // if inserting at first index -> pushFront()
    if(index == 0){
        pushFront(newElement);
        return;
    }

    ListElement<T>* listElement = head;

    // get element at index-1 in list
    for (int i = 0; i < index - 1; i++){
        listElement = listElement->nextElement;


        if(listElement == nullptr){
            std::cout << "Out of range!";
            return;
        }
    }

    // if inserting at last index -> pushBack()
    if(listElement == tail){
        pushBack(newElement);
        return;
    }

    ListElement<T>* nextElement;
    nextElement = listElement->nextElement;

    ListElement<T>* tmp;
    tmp = new ListElement<T>(newElement);
    listElement->nextElement = tmp;
    tmp->nextElement = nextElement;
}


#endif //STRUCTURESIMPLEMENTATIONS_LIST_H
