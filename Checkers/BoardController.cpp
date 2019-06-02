//
// Created by Wojciech Konury on 02/06/2019.
//

#include "BoardController.h"
#include "Movement.h"
#include <iostream>

Cell BoardController::GetBoardItem(int x, int y) {
    return boardArray[y][x];
}

bool BoardController::IsMoveAvaliable(Cell from, Cell dest) {
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

std::vector<Movement> BoardController::GetAvaliableChequers(Color color) {

    std::vector<Movement> moves;
    Movement movement(this->boardArray[0][0], this->boardArray[0][0]);

    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (boardArray[y][x].GetChequer().GetColor() == color) {
                if(this->boardArray[y][x].GetChequer().GetType() == man){
                    this->boardArray[y][x].setAvaliable(false);

                    if((y-1 >= 0) && (x-1 >= 0) && (this->IsMoveAvaliable(this->boardArray[y][x], this->boardArray[y-1][x-1]))){
                        this->boardArray[y][x].setAvaliable(true);
                        movement.SetMovement(this->boardArray[y][x], this->boardArray[y-1][x-1]);
                        moves.push_back(movement);
                    }

                    if((y-1 >= 0) && (x+1 <= 7) && (this->IsMoveAvaliable(this->boardArray[y][x], this->boardArray[y-1][x+1]))){
                        this->boardArray[y][x].setAvaliable(true);
                        movement.SetMovement(this->boardArray[y][x], this->boardArray[y-1][x+1]);
                        moves.push_back(movement);
                    }

                    if((y+1 <= 7) && (x-1 >= 0) && (this->IsMoveAvaliable(this->boardArray[y][x], this->boardArray[y+1][x-1]))){
                        this->boardArray[y][x].setAvaliable(true);
                        movement.SetMovement(this->boardArray[y][x], this->boardArray[y+1][x-1]);
                        moves.push_back(movement);
                    }

                    if((y+1 <= 7) && (x+1 <= 7) && (this->IsMoveAvaliable(this->boardArray[y][x], this->boardArray[y+1][x+1]))){
                        this->boardArray[y][x].setAvaliable(true);
                        movement.SetMovement(this->boardArray[y][x], this->boardArray[y+1][x+1]);
                        moves.push_back(movement);
                    }
                } else if(this->boardArray[y][x].GetChequer().GetType() == king){
                    for (int i = 1; i < 8; ++i) {

                        if((y-i >= 0) && (x-i >=0) && (this->IsMoveAvaliable(this->boardArray[y][x], this->boardArray[y-i][x-i]))){
                            this->boardArray[y][x].setAvaliable(true);
                            movement.SetMovement(this->boardArray[y][x], this->boardArray[y-i][x-i]);
                            moves.push_back(movement);
                        } else if((y-i >= 0) && (x+i <=7) && (this->IsMoveAvaliable(this->boardArray[y][x], this->boardArray[y-i][x+i]))){
                            this->boardArray[y][x].setAvaliable(true);
                            movement.SetMovement(this->boardArray[y][x], this->boardArray[y-i][x+i]);
                            moves.push_back(movement);
                        } else if((y+i <= 7) && (x-i >= 0) && (this->IsMoveAvaliable(this->boardArray[y][x], this->boardArray[y+i][x-i]))){
                            this->boardArray[y][x].setAvaliable(true);
                            movement.SetMovement(this->boardArray[y][x], this->boardArray[y+i][x-i]);
                            moves.push_back(movement);
                        }else if((y+i <= 7) && (x+i <= 7) && (this->IsMoveAvaliable(this->boardArray[y][x], this->boardArray[y+i][x+i]))){
                            this->boardArray[y][x].setAvaliable(true);
                            movement.SetMovement(this->boardArray[y][x], this->boardArray[y+i][x+i]);
                            moves.push_back(movement);
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
    return moves;
}

Capture BoardController::IsCaptureAvalible(Cell from, Cell dest) {
    Capture capture;

    if((dest.GetX() - from.GetX() == 0) || (dest.GetY() - from.GetY() == 0)){
        capture.SetMovement(from, dest, Cell());
        capture.SetIsCapture(false);
        return capture;
    }


    int vecX = (dest.GetX() - from.GetX())/ abs((dest.GetX() - from.GetX()));
    int vecY = (dest.GetY() - from.GetY())/ abs((dest.GetY() - from.GetY()));
    Cell mid = this->GetBoardItem(from.GetX() + vecX, from.GetY() + vecY);
    int x = from.GetX();
    int y = from.GetY();
    int enemy = 0;

    if(from.GetChequer().GetType() == man){
        if(dest.isFreeToMove() && (from.GetChequer().GetColor() != mid.GetChequer().GetColor()) && mid.isChequer()){
            capture.SetMovement(from, dest, mid);
            capture.SetIsCapture(true);
            return capture;
        } else{
            capture.SetMovement(from, dest, Cell());
            capture.SetIsCapture(false);
            return capture;
        }
    } else if(from.GetChequer().GetType() == king){
        while (x != dest.GetX() && y != dest.GetY()){
            x = x + vecX;
            y = y + vecY;
            mid = this->GetBoardItem(x, y);

            if(mid.GetChequer().GetColor() == from.GetChequer().GetColor()){
                capture.SetMovement(from, dest, Cell());
                capture.SetIsCapture(false);
                return capture;
            }

            if((mid.GetChequer().GetColor() != from.GetChequer().GetColor()) && (mid.GetChequer().GetColor() != noColor)){
                enemy++;
            }
        }

        if (enemy == 1 && dest.isFreeToMove()){
            capture.SetMovement(from, dest, mid);
            capture.SetIsCapture(true);
            return capture;
        } else{
            capture.SetMovement(from, dest, Cell());
            capture.SetIsCapture(false);
            return capture;
        }
    }
}


bool BoardController::GetAvalibleCapture(Color color) {
    bool isAnyCapture = false;

    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if(this->boardArray[y][x].GetChequer().GetColor() == color){
                if(this->boardArray[y][x].GetChequer().GetType() == man){

                    if((y-2 >= 0) && (x-2 >= 0) && (this->IsCaptureAvalible(this->boardArray[y][x], this->boardArray[y-2][x-2]).IsCapture())){
                        this->boardArray[y][x].setAvaliable(true);
                        isAnyCapture = true;
                        std::cout << "Avalible Capture: x=" << x << " y=" << y << std::endl;
                    } else if((y-2 >= 0) && (x+2 <= 7) && (this->IsCaptureAvalible(this->boardArray[y][x], this->boardArray[y-2][x+2]).IsCapture())){
                        this->boardArray[y][x].setAvaliable(true);
                        isAnyCapture = true;
                        std::cout << "Avalible Capture: x=" << x << " y=" << y << std::endl;
                    }else if((y+2 <= 7) && (x-2 >= 0) && (this->IsCaptureAvalible(this->boardArray[y][x], this->boardArray[y+2][x-2]).IsCapture())){
                        this->boardArray[y][x].setAvaliable(true);
                        isAnyCapture = true;
                        std::cout << "Avalible Capture: x=" << x << " y=" << y << std::endl;
                    }else if((y+2 <= 7) && (x+2 <= 7) && (this->IsCaptureAvalible(this->boardArray[y][x], this->boardArray[y+2][x+2]).IsCapture())){
                        this->boardArray[y][x].setAvaliable(true);
                        isAnyCapture = true;
                        std::cout << "Avalible Capture: x=" << x << " y=" << y << std::endl;
                    } else{
                        this->boardArray[y][x].setAvaliable(false);
                    }
                } else if(this->boardArray[y][x].GetChequer().GetType() == king){

                    for (int i = 1; i < 8; ++i) {

                        if((y-i >= 0) && (x-i >=0) && (this->IsCaptureAvalible(this->boardArray[y][x], this->boardArray[y-i][x-i]).IsCapture())){
                            this->boardArray[y][x].setAvaliable(true);
                            isAnyCapture = true;
                            std::cout << "Avalible Capture: x=" << x << " y=" << y << std::endl;
                            break;
                        } else if((y-i >= 0) && (x+i <=7) && (this->IsCaptureAvalible(this->boardArray[y][x], this->boardArray[y-i][x+i]).IsCapture())){
                            this->boardArray[y][x].setAvaliable(true);
                            isAnyCapture = true;
                            std::cout << "Avalible Capture: x=" << x << " y=" << y << std::endl;
                            break;
                        } else if((y+i <= 7) && (x-i >= 0) && (this->IsCaptureAvalible(this->boardArray[y][x], this->boardArray[y+i][x-i]).IsCapture())){
                            this->boardArray[y][x].setAvaliable(true);
                            isAnyCapture = true;
                            std::cout << "Avalible Capture: x=" << x << " y=" << y << std::endl;
                            break;
                        }else if((y+i <= 7) && (x+i <= 7) && (this->IsCaptureAvalible(this->boardArray[y][x], this->boardArray[y+i][x+i]).IsCapture())){
                            this->boardArray[y][x].setAvaliable(true);
                            isAnyCapture = true;
                            std::cout << "Avalible Capture: x=" << x << " y=" << y << std::endl;
                            break;
                        } else{
                            this->boardArray[y][x].setAvaliable(false);
                        }
                    }

                }
            }
        }
    }
    return  isAnyCapture;
}

void BoardController::MakeKing(Cell dest, Color color) {
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


void BoardController::MakeMove(Cell from, Cell dest) {
    this->Hide(from.GetX(), from.GetY());
    this->Show(dest.GetX(), dest.GetY(), from.GetChequer());
    this->MakeKing(dest, from.GetChequer().GetColor());
}

void BoardController::MakeCapture(Cell from, Cell dest) {
    int vecX = (dest.GetX() - this->GetChosen().GetX())/abs((dest.GetX() - this->GetChosen().GetX()));
    int vecY = (dest.GetY() - this->GetChosen().GetY())/abs((dest.GetX() - this->GetChosen().GetX()));
    Cell mid = this->GetBoardItem(dest.GetX() - vecX, dest.GetY() - vecY);
    int x = this->GetChosen().GetX();
    int y = this->GetChosen().GetY();

    this->Hide(this->GetChosen().GetX(), this->GetChosen().GetY());
    this->Show(dest.GetX(), dest.GetY(), this->GetChosen().GetChequer());
    this->SetChosen(dest.GetX(), dest.GetY());
    this->MakeKing(dest, this->GetChosen().GetChequer().GetColor());

    if(this->GetChosen().GetChequer().GetType() == man){
        this->Hide(mid.GetX(), mid.GetY());

        //Check for new capture
        if((dest.GetY()-2 >= 0) && (dest.GetX()-2 >= 0) && (this->IsCaptureAvalible(this->boardArray[dest.GetY()][dest.GetX()], this->boardArray[dest.GetY()-2][dest.GetX()-2]).IsCapture())){
        } else if((dest.GetY()-2 >= 0) && (dest.GetX()+2 <= 7) && (this->IsCaptureAvalible(this->boardArray[dest.GetY()][dest.GetX()], this->boardArray[dest.GetY()-2][dest.GetX()+2]).IsCapture())){
        }else if((dest.GetY()+2 <= 7) && (dest.GetX()-2 >= 0) && (this->IsCaptureAvalible(this->boardArray[dest.GetY()][dest.GetX()], this->boardArray[dest.GetY()+2][dest.GetX()-2]).IsCapture())){
        }else if((dest.GetY()+2 <= 7) && (dest.GetX()+2 <= 7) && (this->IsCaptureAvalible(this->boardArray[dest.GetY()][dest.GetX()], this->boardArray[dest.GetY()+2][dest.GetX()+2]).IsCapture())){
        } else{
            this->SwitchTurn();
        }
    } else if(this->GetChosen().GetChequer().GetType() == king){
        while (x != dest.GetX() && y != dest.GetY()){
            x = x + vecX;
            y = y + vecY;
            mid = this->GetBoardItem(x, y);


            if((mid.GetChequer().GetColor() != this->GetChosen().GetChequer().GetColor()) && (mid.GetChequer().GetColor() != noColor)){
                this->Hide(mid.GetX(), mid.GetY());
                break;
            }
        }

        for (int i = 1; i < 8; ++i) {

            if((y-i >= 0) && (x-i >=0) && (this->IsCaptureAvalible(this->boardArray[dest.GetY()][dest.GetX()], this->boardArray[y-i][x-i]).IsCapture())){
                break;
            } else if((y-i >= 0) && (x+i <=7) && (this->IsCaptureAvalible(this->boardArray[dest.GetY()][dest.GetX()], this->boardArray[y-i][x+i]).IsCapture())){
                break;
            } else if((y+i <= 7) && (x-i >= 0) && (this->IsCaptureAvalible(this->boardArray[dest.GetY()][dest.GetX()], this->boardArray[y+i][x-i]).IsCapture())){
                break;
            }else if((y+i <= 7) && (x+i <= 7) && (this->IsCaptureAvalible(this->boardArray[dest.GetY()][dest.GetX()], this->boardArray[y+i][x+i]).IsCapture())){
                break;
            } else{
                this->SwitchTurn();
            }
        }
    }

}

void BoardController::SetChosen(int x, int y) {
    this->chosen = this->boardArray[y][x];
}

Cell BoardController::GetChosen() {
    return chosen;
}

void BoardController::SetIsChosen(bool is) {
    this->isChosen = is;
}

bool BoardController::IsChosen() {
    return isChosen;
}

//Cell &BoardController::GetBoard() {
//    return &&boardArray;
//}




