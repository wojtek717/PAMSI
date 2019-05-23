//
// Created by Wojciech Konury on 23/05/2019.
//

#include "ChequerRep.h"

ChequerRep::ChequerRep(ChequerType type, Color color) {
    this->type = type;
    this->color = color;
}

void ChequerRep::SetChequer(ChequerType type, Color color) {
    this->type  = type;
    this->color = color;
}

ChequerType ChequerRep::GetType() {
    return this->type;
}

Color ChequerRep::GetColor() {
    return this->color;
}

ChequerRep::ChequerRep() {
    this->type = noType;
    this->color = noColor;
}
