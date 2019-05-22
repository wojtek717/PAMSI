//
// Created by Wojciech Konury on 21/05/2019.
//

#include "Cell.h"

Cell::Cell(int posx, int posy, Chequer chequer, sf::Texture texture) {
    this->posx = posx;
    this->posy = posy;
    this->chequer = chequer;
    this->avaliable = false;
    this->color = no;
    this->playAble = false;

    this->chequerSprite.setPosition(posx, posy);
    this->chequerSprite.setTexture(texture);
}

Cell::Cell(int posx, int posy) {
    this->posx = posx;
    this->posy = posy;
    this->chequer = noChequer;
    this->avaliable = false;
    this->color = no;
    this->playAble = false;

    this->chequerSprite.setPosition(posx, posy);
}

Cell::Cell() {
    this->posx = 0;
    this->posy = 0;
    this->chequer = noChequer;
    this->avaliable = false;
    this->color = no;
    this->playAble = false;

    this->chequerSprite.setPosition(posx, posy);
}

void Cell::SetChequer(Chequer chequer, sf::Texture &texture) {
    this->chequer = chequer;

    this->chequerSprite.setTexture(texture);
}

bool Cell::isChequer() {
    return !(chequer == noChequer);
}

void Cell::SetColor(Color color) {
    this->color = color;
}

Color Cell::GetColor() {
    return this->color;
}

Chequer Cell::GetChequer() {
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
    this->chequer = noChequer;
    this->color = no;
    this->chequerSprite.setTexture(noTexture);
}

void Cell::Show(Color color, Chequer chequer, sf::Texture &Texture) {
    this->color = color;
    this->chequer = chequer;
    this->chequerSprite.setTexture(Texture);
}

bool Cell::isPlayAble() {
    return this->playAble;
}

int Cell::GetX() {
    return this->posx;
}

int Cell::GetY() {
    return this->posy;
}
