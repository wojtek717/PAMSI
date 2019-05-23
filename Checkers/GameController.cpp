//
// Created by Wojciech Konury on 21/05/2019.
//

#include "GameController.h"

GameController::GameController() {
    this->turn = white;
    this->isChosen = false;
}

void GameController::SetBoardTexture(std::string boardTexture) {
    this->boardTexture.loadFromFile(boardTexture);

    this->board.setTexture(this->boardTexture);
}

sf::Sprite GameController::GetBoardSprite() {
    return board;
}

void GameController::SetNoChequerTexture(std::string noTexture) {
    this->noChequerTexture.loadFromFile(noTexture);
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
                    this->boardArray[y][x].SetChequer(man, black, blackManChequerTexture);
                    this->boardArray[y][x].setPlayAble();
                }
            }

            if(y==3 || y==4){
                if((y%2 == 0 && x%2 != 0) || (y%2 != 0 && x%2 == 0)){
                    this->boardArray[y][x].setPlayAble();
                }
            }

            //White
            if(y > 4){
                if((y%2 == 0 && x%2 != 0) || (y%2 != 0 && x%2 == 0)){
                    this->boardArray[y][x].SetChequer(man, white, whiteManChequerTexture);
                    this->boardArray[y][x].setPlayAble();
                }
            }
        }
    }
}

Cell GameController::GetBoardItem(int x, int y) {
    return boardArray[y][x];
}

Color GameController::GetTurn() {
    return turn;
}

void GameController::SetTurn(Color turn) {
    this->turn = turn;
}

Color GameController::SwitchTurn() {
    if(this->turn == white){
        this->turn = black;
    }

    if(this->turn == black){
        this->turn = white;
    }

    return this->turn;
}

void GameController::GetAvaliableChequers(Color color) {

    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (boardArray[y][x].GetChequer().GetColor() == color) {
                if (boardArray[y][x].GetChequer().GetType() == man) {
                    if (y - 1 >= 0 && x - 1 >= 0 && !boardArray[y - 1][x - 1].isChequer()) {
                        this->boardArray[y][x].setAvaliable(true);
                    } else if (y - 1 >= 0 && x + 1 <= 7 && !boardArray[y - 1][x + 1].isChequer()) {
                        this->boardArray[y][x].setAvaliable(true);
                    }else{
                        this->boardArray[y][x].setAvaliable(false);
                    }
                } else if(boardArray[y][x].GetChequer().GetType() == king){
                    //Tutaj napisac warnunki czy damka ma mozliwe opcje poruszenia sie
                }
            }else{
                this->boardArray[y][x].setAvaliable(false);
            }
        }
    }
}


void GameController::Hide(int x, int y) {
    this->boardArray[y][x].Hide(noChequerTexture);
}

void GameController::Show(int x, int y, ChequerRep chequer) {
    if(chequer.GetType() == man && chequer.GetColor() == white){
        this->boardArray[y][x].Show(chequer, this->whiteManChequerTexture);
    } else if(chequer.GetType() == king && chequer.GetColor() == white){
        this->boardArray[y][x].Show(chequer, this->whiteKingChequerTexture);
    } else if(chequer.GetType() == man && chequer.GetColor() == black){
        this->boardArray[y][x].Show(chequer, this->blackManChequerTexture);
    } else if(chequer.GetType() == king && chequer.GetColor() == black){
        this->boardArray[y][x].Show(chequer, this->blackKingChequerTexture);
    }
}


void GameController::SetChosen(int x, int y) {
    this->chosen = this->boardArray[y][x];
}

Cell GameController::GetChosen() {
    return chosen;
}

void GameController::SetIsChosen(bool is) {
    this->isChosen = is;
}

bool GameController::IsChosen() {
    return isChosen;
}

bool GameController::IsMoveAvaliable(Cell from, Cell dest) {
    if(dest.isFreeToMove()){
        if(from.GetChequer().GetType() == man){
            if(from.GetChequer().GetColor() == white){
                return (from.GetY() - dest.GetY() == 1) && (abs(from.GetX() - dest.GetX()) == 1);
            }else if(from.GetChequer().GetColor() == black){
                return (from.GetY() - dest.GetY() == -1) && (abs(from.GetX() - dest.GetX()) == 1);
            }
        } else if(from.GetChequer().GetType() == king){
            //Sprawdzenie dla damki dla obu kolorow
        }
    } else{
        return false;
    }

}




