//
// Created by Wojciech Konury on 21/05/2019.
//

#ifndef CHECKERS_CELL_H
#define CHECKERS_CELL_H

#include <SFML/Graphics.hpp>
#include "Chequer.h"
#include "Color.h"

class Cell {
    int posx;
    int posy;
    Chequer chequer;
    Color color;
    bool avaliable;
    bool playAble;


public:
    sf::Sprite chequerSprite;

    Cell(int posx, int posy, Chequer chequer, sf::Texture texture);
    Cell(int posx, int posy);
    Cell();

    void SetChequer(Chequer chequer, sf::Texture &texture);
    void SetColor(Color color);
    void setAvaliable(bool a);
    void setPlayAble();

    bool isChequer();
    bool isAvaliable();
    bool isPlayAble();

    Color GetColor();
    Chequer GetChequer();
    int GetX();
    int GetY();

    void Hide(sf::Texture noTexture);
    void Show(Color color, Chequer chequer, sf::Texture &Texture);
};


#endif //CHECKERS_CELL_H
