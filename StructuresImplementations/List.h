//
// Created by Wojciech Konury on 09/03/2019.
//

#ifndef STRUCTURESIMPLEMENTATIONS_LIST_H
#define STRUCTURESIMPLEMENTATIONS_LIST_H

#include <iostream>
#include "Container.h"

template <typename T>
class List {
private:
    Container<T> *head;
    Container<T> *tail;

public:
    List(){
        head = nullptr;
        tail = nullptr;
    }

    class Iterator{
        Container<T> *current;

    public:
        Iterator(Container<T>* x) :current(x) {}

        Iterator& operator++() {current = current->nextElement; return *this;}
        bool operator==(const Iterator& rhs) const {return &current->data==&rhs.current->data;}
        bool operator!=(const Iterator& rhs) const {return &current->data!=&rhs.current->data;}
        T& operator*() {return current->data;}
    };

    void pushBack(const T& newElement);
    void pushFront(const T& newElement);
    void insert(const T& newElement , int index);
    void remove(const T& element);

    T& operator[](int index);

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end(){
        return Iterator(nullptr);
    }

};

template<typename T>
void List<T>::pushBack(const T &newElement) {
    if(head == nullptr){
        head = new Container<T>(newElement);
        tail = head;
    } else{
        Container<T>* tmp;
        tmp = new Container<T>(newElement);
        tail->nextElement = tmp;

        tail = tmp;
        tail->nextElement = nullptr;
    }
}

template<typename T>
void List<T>::pushFront(const T &newElement) {
    if(head == nullptr){
        head = new Container<T>(newElement);
        tail = head;
    } else{
        Container<T>* tmp;
        tmp = new Container<T>(newElement);

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

    Container<T>* listElement = head;

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

    Container<T>* nextElement;
    nextElement = listElement->nextElement;

    Container<T>* tmp;
    tmp = new Container<T>(newElement);
    listElement->nextElement = tmp;
    tmp->nextElement = nextElement;
}

template<typename T>
void List<T>::remove(const T &element) {
    Container<T>* tmp;
    tmp = new Container<T>(element);

    Container<T>* listElement = head;
    Container<T>* previousListElement = nullptr;

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
    Container<T>* listElement = head;


    for(int i = 0; i < index; i++){
        listElement = listElement->nextElement;

        if(listElement == nullptr){
            //TODO Dodac wyjatek!
        }
    }

    return listElement->data;
}


#endif //STRUCTURESIMPLEMENTATIONS_LIST_H
