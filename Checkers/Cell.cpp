//
// Created by Wojciech Konury on 21/05/2019.
//

#include "Cell.h"

Cell::Cell(int posx, int posy, Chequer chequer, sf::Texture texture) {
    this->posx = posx;
    this->posy = posy;
    this->chequer = chequer;

    this->chequerSprite.setPosition(posx, posy);
    this->chequerSprite.setTexture(texture);
}

Cell::Cell(int posx, int posy) {
    this->posx = posx;
    this->posy = posy;
    this->chequer = none;

    this->chequerSprite.setPosition(posx, posy);
}

Cell::Cell() {
    this->posx = 0;
    this->posy = 0;
    this->chequer = none;

    this->chequerSprite.setPosition(posx, posy);
}

void Cell::SetChequer(Chequer chequer, sf::Texture &texture) {
    this->chequer = chequer;

    this->chequerSprite.setTexture(texture);
}

bool Cell::isChequer() {
    return !(chequer == none);
}
