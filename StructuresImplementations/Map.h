//
// Created by Wojciech Konury on 15/03/2019.
//

#ifndef STRUCTURESIMPLEMENTATIONS_MAP_H
#define STRUCTURESIMPLEMENTATIONS_MAP_H

#include <string>
#include <iostream>

#define SIZE 10000
#define SEED 123

template <typename KeyType , typename ValueType >
class Map {
private:
ValueType map[SIZE];

int hash(std::string Key);
int hash(int Key);

public:
    Map(){}

    void insert(const KeyType& key, const ValueType& value);

    void remove(std::string key);
    void remove(int key);

    ValueType& operator [] (const KeyType& key);




};


template<typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::insert(const KeyType &key, const ValueType &value) {
    map[hash(key)] = value;
}

template<typename KeyType, typename ValueType>
ValueType &Map<KeyType, ValueType>::operator[](const KeyType &key) {
    return map[hash(key)];
}

template<typename KeyType, typename ValueType>
int Map<KeyType, ValueType>::hash(std::string Key) {
    int hash = 0;

    for(int i = 0; i < Key.length(); i++)
    {
        hash = (hash * SEED) + Key[i];
    }

    return hash % SIZE;
}

template<typename KeyType, typename ValueType>
int Map<KeyType, ValueType>::hash(int Key) {
    return Key % SIZE;
}

template<typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::remove(std::string key) {
    map[hash(key)] = "";
}

template<typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::remove(int key) {
    map[hash(key)] = 0;
}


#endif //STRUCTURESIMPLEMENTATIONS_MAP_H
