//
// Created by Wojciech Konury on 21/05/2019.
//

#include "GameController.h"

GameController::GameController() {

}

void GameController::SetBoardTexture(std::string boardTexture) {
    this->boardTexture.loadFromFile(boardTexture);

    this->board.setTexture(this->boardTexture);
}

sf::Sprite GameController::GetBoardSprite() {
    return board;
}

void GameController::SetMansTexture(std::string whiteManChequerTexture, std::string blackManChequerTexture) {
    this->whiteManChequerTexture.loadFromFile(whiteManChequerTexture);
    this->blackManChequerTexture.loadFromFile(blackManChequerTexture);
}

void GameController::SetKingsTexture(std::string whiteKingChequerTexture, std::string blackKingChequerTexture) {
    this->whiteKingChequerTexture.loadFromFile(whiteKingChequerTexture);
    this->blackKingChequerTexture.loadFromFile(blackKingChequerTexture);
}

void GameController::SeedChequers() {

    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            this->boardArray[y][x] = Cell(x * CELLSIZE, y * CELLSIZE);

            //Black
            if(y < 3){
                if((y%2 == 0 && x%2 != 0) || (y%2 != 0 && x%2 == 0)){
                    this->boardArray[y][x].SetChequer(blackMan, blackManChequerTexture);
                }
            }

            //White
            if(y > 4){
                if((y%2 == 0 && x%2 != 0) || (y%2 != 0 && x%2 == 0)){
                    this->boardArray[y][x].SetChequer(whiteMan, whiteManChequerTexture);
                }
            }
        }
    }
}

Cell GameController::GetBoardItem(int x, int y) {
    return boardArray[y][x];
}
