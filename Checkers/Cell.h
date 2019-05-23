//
// Created by Wojciech Konury on 21/05/2019.
//

#ifndef CHECKERS_CELL_H
#define CHECKERS_CELL_H

#include <SFML/Graphics.hpp>
#include "ChequerType.h"
#include "Color.h"
#include "ChequerRep.h"

class Cell {
    int posx;
    int posy;
    ChequerRep chequer;
    bool avaliable;
    bool playAble;


public:
    sf::Sprite chequerSprite;


    Cell(int posx, int posy);
    Cell();

    void SetChequer(ChequerType type, Color color, sf::Texture &texture);
    void SetChequer(ChequerType type, Color color);
    void setAvaliable(bool a);
    void setPlayAble();

    bool isChequer();
    bool isAvaliable();
    bool isPlayAble();

    ChequerRep GetChequer();
    int GetX();
    int GetY();

    void Hide(sf::Texture noTexture);
    void Show(ChequerRep chequer, sf::Texture &Texture);
};


#endif //CHECKERS_CELL_H
