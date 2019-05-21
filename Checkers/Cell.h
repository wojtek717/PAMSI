//
// Created by Wojciech Konury on 21/05/2019.
//

#ifndef CHECKERS_CELL_H
#define CHECKERS_CELL_H

#include <SFML/Graphics.hpp>
#include "Chequer.h"

class Cell {
    int posx;
    int posy;
    Chequer chequer;


public:
    sf::Sprite chequerSprite;

    Cell(int posx, int posy, Chequer chequer, sf::Texture texture);
    Cell(int posx, int posy);
    Cell();

    void SetChequer(Chequer chequer, sf::Texture &texture);
    bool isChequer();
};


#endif //CHECKERS_CELL_H
