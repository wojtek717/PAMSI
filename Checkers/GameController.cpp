//
// Created by Wojciech Konury on 21/05/2019.
//

#include <iostream>
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
    }else if(this->turn == black){
        this->turn = white;
    }



    return this->turn;
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

            return abs(from.GetX() - dest.GetX()) == abs(from.GetY() - dest.GetY());
        }
    } else{
        return false;
    }
}

bool GameController::IsCaptureAvalible(Cell from, Cell dest) {
    int vecX = (dest.GetX() - from.GetX())/2;
    int vecY = (dest.GetY() - from.GetY())/2;
    Cell mid = this->GetBoardItem(from.GetX() + vecX, from.GetY() + vecY);

    if(dest.isFreeToMove() && (from.GetChequer().GetColor() != mid.GetChequer().GetColor()) && mid.isChequer()){
        return true;
    } else{
        return false;
    }
}



void GameController::GetAvaliableChequers(Color color) {

    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (boardArray[y][x].GetChequer().GetColor() == color) {
                if(this->boardArray[y][x].GetChequer().GetType() == man){
                    if((y-1 >= 0) && (x-1 >= 0) && (this->IsMoveAvaliable(this->boardArray[y][x], this->boardArray[y-1][x-1]))){
                        this->boardArray[y][x].setAvaliable(true);
                    } else if((y-1 >= 0) && (x+1 <= 7) && (this->IsMoveAvaliable(this->boardArray[y][x], this->boardArray[y-1][x+1]))){
                        this->boardArray[y][x].setAvaliable(true);
                    }else if((y+1 <= 7) && (x-1 >= 0) && (this->IsMoveAvaliable(this->boardArray[y][x], this->boardArray[y+1][x-1]))){
                        this->boardArray[y][x].setAvaliable(true);
                    }else if((y+1 <= 7) && (x+1 <= 7) && (this->IsMoveAvaliable(this->boardArray[y][x], this->boardArray[y+1][x+1]))){
                        this->boardArray[y][x].setAvaliable(true);
                    } else{
                        this->boardArray[y][x].setAvaliable(false);
                    }
                } else if(this->boardArray[y][x].GetChequer().GetType() == king){
                    for (int i = 1; i < 8; ++i) {

                        if((y-i >= 0) && (x-i >=0) && (this->IsMoveAvaliable(this->boardArray[y][x], this->boardArray[y-i][x-i]))){
                            this->boardArray[y][x].setAvaliable(true);
                            break;
                        } else if((y-i >= 0) && (x+i <=7) && (this->IsMoveAvaliable(this->boardArray[y][x], this->boardArray[y-i][x+i]))){
                            this->boardArray[y][x].setAvaliable(true);
                            break;
                        } else if((y+i <= 7) && (x-i >= 0) && (this->IsMoveAvaliable(this->boardArray[y][x], this->boardArray[y+i][x-i]))){
                            this->boardArray[y][x].setAvaliable(true);
                            break;
                        }else if((y+i <= 7) && (x+i <= 7) && (this->IsMoveAvaliable(this->boardArray[y][x], this->boardArray[y+i][x+i]))){
                            this->boardArray[y][x].setAvaliable(true);
                            break;
                        } else{
                            this->boardArray[y][x].setAvaliable(false);
                        }
                    }
                }
            }else{
                this->boardArray[y][x].setAvaliable(false);
            }
        }
    }
}

bool GameController::GetAvalibleCapture(Color color) {
    bool isAnyCapture = false;

    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if(this->boardArray[y][x].GetChequer().GetColor() == color){
                if(this->boardArray[y][x].GetChequer().GetType() == man){

                    if((y-2 >= 0) && (x-2 >= 0) && (this->IsCaptureAvalible(this->boardArray[y][x], this->boardArray[y-2][x-2]))){
                        this->boardArray[y][x].setAvaliable(true);
                        isAnyCapture = true;
                        std::cout << "Avalible Capture: x=" << x << " y=" << y << std::endl;
                    } else if((y-2 >= 0) && (x+2 <= 7) && (this->IsCaptureAvalible(this->boardArray[y][x], this->boardArray[y-2][x+2]))){
                        this->boardArray[y][x].setAvaliable(true);
                        isAnyCapture = true;
                        std::cout << "Avalible Capture: x=" << x << " y=" << y << std::endl;
                    }else if((y+2 <= 7) && (x-2 >= 0) && (this->IsCaptureAvalible(this->boardArray[y][x], this->boardArray[y+2][x-2]))){
                        this->boardArray[y][x].setAvaliable(true);
                        isAnyCapture = true;
                        std::cout << "Avalible Capture: x=" << x << " y=" << y << std::endl;
                    }else if((y+2 <= 7) && (x+2 <= 7) && (this->IsCaptureAvalible(this->boardArray[y][x], this->boardArray[y+2][x+2]))){
                        this->boardArray[y][x].setAvaliable(true);
                        isAnyCapture = true;
                        std::cout << "Avalible Capture: x=" << x << " y=" << y << std::endl;
                    } else{
                        this->boardArray[y][x].setAvaliable(false);
                    }

                }
            }
        }
    }
    return  isAnyCapture;
}

void GameController::MakeMove(Cell dest) {
    this->Hide(this->GetChosen().GetX(), this->GetChosen().GetY());
    this->Show(dest.GetX(), dest.GetY(), this->GetChosen().GetChequer());
    this->SetIsChosen(false);
    this->MakeKing(dest, this->GetChosen().GetChequer().GetColor());
    this->SwitchTurn();
}

void GameController::MakeCapture(Cell dest) {
    int vecX = (dest.GetX() - this->GetChosen().GetX())/2;
    int vecY = (dest.GetY() - this->GetChosen().GetY())/2;
    Cell mid = this->GetBoardItem(dest.GetX() - vecX, dest.GetY() - vecY);


    this->Hide(this->GetChosen().GetX(), this->GetChosen().GetY());
    this->Hide(mid.GetX(), mid.GetY());
    this->Show(dest.GetX(), dest.GetY(), this->GetChosen().GetChequer());
    this->SetChosen(dest.GetX(), dest.GetY());
    this->MakeKing(dest, this->GetChosen().GetChequer().GetColor());


    if((dest.GetY()-2 >= 0) && (dest.GetX()-2 >= 0) && (this->IsCaptureAvalible(this->boardArray[dest.GetY()][dest.GetX()], this->boardArray[dest.GetY()-2][dest.GetX()-2]))){
        //this->boardArray[dest.GetY()][dest.GetX()].setAvaliable(true);
    } else if((dest.GetY()-2 >= 0) && (dest.GetX()+2 <= 7) && (this->IsCaptureAvalible(this->boardArray[dest.GetY()][dest.GetX()], this->boardArray[dest.GetY()-2][dest.GetX()+2]))){
        //this->boardArray[dest.GetY()][dest.GetX()].setAvaliable(true);
    }else if((dest.GetY()+2 <= 7) && (dest.GetX()-2 >= 0) && (this->IsCaptureAvalible(this->boardArray[dest.GetY()][dest.GetX()], this->boardArray[dest.GetY()+2][dest.GetX()-2]))){
        //this->boardArray[dest.GetY()][dest.GetX()].setAvaliable(true);
    }else if((dest.GetY()+2 <= 7) && (dest.GetX()+2 <= 7) && (this->IsCaptureAvalible(this->boardArray[dest.GetY()][dest.GetX()], this->boardArray[dest.GetY()+2][dest.GetX()+2]))){
        //this->boardArray[dest.GetY()][dest.GetX()].setAvaliable(true);
    } else{
       this->SwitchTurn();
    }

}

void GameController::MakeKing(Cell dest, Color color) {
    if(color == white){
        if (dest.GetY() == 0){
            this->boardArray[dest.GetY()][dest.GetX()].SetChequer(king, color);
            std::cout << "ZMIANA" << std::endl;
        }
    }else if(color == black){
        if (dest.GetY() == 7){
            this->boardArray[dest.GetY()][dest.GetX()].SetChequer(king, color);
            std::cout << "ZMIANA" << std::endl;
        }
    }
}





