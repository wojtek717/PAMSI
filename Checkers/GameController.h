//
// Created by Wojciech Konury on 21/05/2019.
//

#ifndef CHECKERS_GAMECONTROLLER_H
#define CHECKERS_GAMECONTROLLER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Cell.h"
#include "Color.h"

#define CELLSIZE 110


class GameController {
private:
    //Game
    Color turn;
    Cell chosen;
    bool isChosen;

    //Textures
    sf::Texture boardTexture;
    sf::Texture whiteManChequerTexture;
    sf::Texture blackManChequerTexture;
    sf::Texture whiteKingChequerTexture;
    sf::Texture blackKingChequerTexture;
    sf::Texture noChequerTexture;

    //Sprites
    sf::Sprite board;

    Cell boardArray[8][8];

public:
    GameController();

    void SetBoardTexture(std::string boardTexture);
    void SetNoChequerTexture(std::string noTexture);
    void SetMansTexture(std::string whiteManChequerTexture, std::string blackManChequerTexture);
    void SetKingsTexture(std::string whiteKingChequerTexture, std::string blackKingChequerTexture);

    void SetTurn(Color turn);
    void SetChosen(int x, int y);
    void SetIsChosen(bool is);

    sf::Sprite GetBoardSprite();

    Cell GetBoardItem(int x, int y);
    Color GetTurn();
    void GetAvaliableChequers(Color color);
    Cell GetChosen();
    bool IsChosen();
    bool IsMoveAvaliable(int destx, int desty);


    void SeedChequers();
    Color SwitchTurn();

    void Hide(int x, int y);
    void Show(int x, int y, Chequer chequer);
};


#endif //CHECKERS_GAMECONTROLLER_H
