//
// Created by Wojciech Konury on 09/03/2019.
//

#ifndef STRUCTURESIMPLEMENTATIONS_ELEMENT_H
#define STRUCTURESIMPLEMENTATIONS_ELEMENT_H


template <typename T>
struct Container {
    T data;
    Container* nextElement;

public:

    Container(){

    }

    Container(T element){
        data = element;
        nextElement = nullptr;
    }

};


#endif //STRUCTURESIMPLEMENTATIONS_ELEMENT_H
