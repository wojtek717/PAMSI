//
// Created by Wojciech Konury on 21/05/2019.
//

#ifndef CHECKERS_GAMECONTROLLER_H
#define CHECKERS_GAMECONTROLLER_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Cell.h"

#define CELLSIZE 110


class GameController {
private:
    //Textures
    sf::Texture boardTexture;
    sf::Texture whiteManChequerTexture;
    sf::Texture blackManChequerTexture;
    sf::Texture whiteKingChequerTexture;
    sf::Texture blackKingChequerTexture;

    //Sprites
    sf::Sprite board;

    Cell boardArray[8][8];

public:
    GameController();

    void SetBoardTexture(std::string boardTexture);
    void SetMansTexture(std::string whiteManChequerTexture, std::string blackManChequerTexture);
    void SetKingsTexture(std::string whiteKingChequerTexture, std::string blackKingChequerTexture);

    sf::Sprite GetBoardSprite();
    Cell GetBoardItem(int x, int y);

    void SeedChequers();
};


#endif //CHECKERS_GAMECONTROLLER_H
