//
// Created by Wojciech Konury on 23/05/2019.
//

#ifndef CHECKERS_CHEQUERREP_H
#define CHECKERS_CHEQUERREP_H


#include "ChequerType.h"
#include "Color.h"

class ChequerRep {
private:
    ChequerType type;
    Color color;

public:
    ChequerRep(ChequerType type, Color color);
    ChequerRep();

    void SetChequer(ChequerType type, Color color);
    ChequerType GetType();
    Color GetColor();
};


#endif //CHECKERS_CHEQUERREP_H
