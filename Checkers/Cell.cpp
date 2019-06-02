//
// Created by Wojciech Konury on 21/05/2019.
//

#include "Cell.h"
#define CELLSIZE 110


Cell::Cell(int posx, int posy) {
    this->posx = posx;
    this->posy = posy;
    this->avaliable = false;
    this->playAble = false;

    this->chequerSprite.setPosition(posx, posy);
}

Cell::Cell() {
    this->posx = 0;
    this->posy = 0;
    this->avaliable = false;
    this->playAble = false;

    this->chequerSprite.setPosition(posx, posy);
}

void Cell::SetChequer(ChequerType type, Color color, sf::Texture &texture) {
    this->chequer.SetChequer(type, color);

    this->chequerSprite.setTexture(texture);
}

bool Cell::isChequer() {
    return !(chequer.GetType() == noType && chequer.GetColor() == noColor);
}

ChequerRep Cell::GetChequer() {
    return this->chequer;
}

void Cell::setAvaliable(bool a) {
    this->avaliable = a;
}

bool Cell::isAvaliable() {
    return avaliable;
}

void Cell::setPlayAble() {
    this->playAble = true;
}

void Cell::Hide(sf::Texture noTexture) {
    this->chequer.SetChequer(noType, noColor);
    this->chequerSprite.setTexture(noTexture);
}

void Cell::Show(ChequerRep chequer, sf::Texture &Texture) {
    this->chequer.SetChequer(chequer.GetType(), chequer.GetColor());
    this->chequerSprite.setTexture(Texture);
}

bool Cell::isPlayAble() {
    return this->playAble;
}

int Cell::GetX() {
    return this->posx/CELLSIZE;
}

int Cell::GetY() {
    return this->posy/CELLSIZE;
}

void Cell::SetChequer(ChequerType type, Color color) {
    this->chequer.SetChequer(type, color);
}

bool Cell::isFreeToMove() {
    return (!isChequer() && isPlayAble());
}

void Cell::Hide() {
    this->chequer.SetChequer(noType, noColor);
}

void Cell::Show(ChequerRep chequer) {
    this->chequer.SetChequer(chequer.GetType(), chequer.GetColor());
}


