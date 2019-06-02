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
#include "BoardController.h"

#define CELLSIZE 110


class GameController : public BoardController {
private:
    //Game
    Color turn;

    //Textures
    sf::Texture boardTexture;
    sf::Texture whiteManChequerTexture;
    sf::Texture blackManChequerTexture;
    sf::Texture whiteKingChequerTexture;
    sf::Texture blackKingChequerTexture;
    sf::Texture noChequerTexture;

    //Sprites
    sf::Sprite board;

public:
    GameController();

    void SetBoardTexture(std::string boardTexture);
    void SetNoChequerTexture(std::string noTexture);
    void SetMansTexture(std::string whiteManChequerTexture, std::string blackManChequerTexture);
    void SetKingsTexture(std::string whiteKingChequerTexture, std::string blackKingChequerTexture);
    void SetTurn(Color turn);

    sf::Sprite GetBoardSprite();

    Color GetTurn();


    void SeedChequers();
    Color SwitchTurn() override;

    void Hide(int x, int y) override;
    void Show(int x, int y, ChequerRep chequer) override;

};


#endif //CHECKERS_GAMECONTROLLER_H
