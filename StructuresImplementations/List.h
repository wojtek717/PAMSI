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
    void remove(const T& element);

    T& operator[](int index);

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

template<typename T>
void List<T>::remove(const T &element) {
    ListElement<T>* tmp;
    tmp = new ListElement<T>(element);

    ListElement<T>* listElement = head;
    ListElement<T>* previousListElement = nullptr;

    while (listElement != nullptr){

        if(listElement->data == tmp->data){
            if(listElement == head){
                //previousLisElement == nullptr
                head = head->nextElement;
                delete(listElement);
            } else if(listElement->nextElement == nullptr){
                previousListElement->nextElement = nullptr;
                tail = previousListElement;
                delete(listElement);
            } else{
                previousListElement->nextElement = listElement->nextElement;
                delete(listElement);
            }
        }


        previousListElement = listElement;
        listElement = listElement->nextElement;
    }
}

template<typename T>
T &List<T>::operator[](int index) {
    ListElement<T>* listElement = head;


    for(int i = 0; i < index; i++){
        listElement = listElement->nextElement;

        if(listElement == nullptr){
            //TODO Dodac wyjatek!
        }
    }

    return listElement->data;
}


#endif //STRUCTURESIMPLEMENTATIONS_LIST_H
