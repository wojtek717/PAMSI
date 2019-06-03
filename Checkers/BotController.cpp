//
// Created by Wojciech Konury on 02/06/2019.
//

#include "BotController.h"

void BotController::ReadBoard(std::vector<std::vector<Cell>> gameBoard) {
    this->boardArray = gameBoard;
}

Color BotController::SwitchTurn() {
    return noColor;
}

void BotController::Show(int x, int y, ChequerRep chequer) {
    if(chequer.GetType() == man && chequer.GetColor() == white){
        this->boardArray[y][x].Show(chequer);
    } else if(chequer.GetType() == king && chequer.GetColor() == white){
        this->boardArray[y][x].Show(chequer);
    } else if(chequer.GetType() == man && chequer.GetColor() == black){
        this->boardArray[y][x].Show(chequer);
    } else if(chequer.GetType() == king && chequer.GetColor() == black){
        this->boardArray[y][x].Show(chequer);
    }
}

void BotController::Hide(int x, int y) {
    this->boardArray[y][x].Hide();
}

int BotController::EvaluateMove(Cell dest) {
    if(dest.GetX() == 0 || dest.GetX() == 7 || dest.GetY() == 0 || dest.GetY() == 7){
        return 3;
    }else if(dest.GetX() == 1 || dest.GetX() == 6 || dest.GetY() == 1 || dest.GetY() == 6){
        return 2;
    } else{
        return 1;
    }
}

int BotController::EvaluateCapture(Cell capturePos) {
    int typeMultip;

    if(capturePos.GetChequer().GetType() == king){
        typeMultip = 5;
    } else{
        typeMultip = 1;
    }

    if(capturePos.GetX() == 0 || capturePos.GetX() == 7 || capturePos.GetY() == 0 || capturePos.GetY() == 7){
        return (6 * typeMultip);
    }else if(capturePos.GetX() == 1 || capturePos.GetX() == 6 || capturePos.GetY() == 1 || capturePos.GetY() == 6){
        return (5 * typeMultip);
    } else{
        return (4 * typeMultip);
    }
}

void BotController::MakeTree() {
    this->tree.clear();

    std::vector<Movement> movements;
    std::vector<Capture> captures;
    std::vector<std::vector<Cell>> tempBoard = this->boardArray;
    int i = 0;




    captures = this->GetAvalibleCapture(black);
    if(captures.size() == 0){
        //Brak bicia
        movements = this->GetAvaliableChequers(black);

        for (auto &movement : movements) {
            this->MakeMove(movement.from, movement.dest);
            movement.SetScore(this->EvaluateMove(movement.dest));
            Node node = Node(this->boardArray, movement);
            this->boardArray = tempBoard;
            this->tree.push_back(node);
        }
    } else{
        //Wystepuje bicie
        for (auto &capture : captures){
            this->MakeCapture(capture.from, capture.dest);
            capture.SetScore(this->EvaluateCapture(capture.capturePos));
            Node node = Node(this->boardArray, capture);
            this->boardArray = tempBoard;
            this->tree.push_back(node);
        }
    }

    i = 0;
    for (auto &node : this->tree){
        this->boardArray = node.simulatedBoard;
        captures = this->GetAvalibleCapture(white);
        if(captures.size() == 0){
            //Brak bicia
            movements = this->GetAvaliableChequers(white);

            for (auto &movement : movements){
                this->MakeMove(movement.from, movement.dest);
                movement.SetScore(this->EvaluateMove(movement.dest));
                Node node = Node(this->boardArray, movement);
                this->tree[i].subtree.push_back(node);
            }
        }else{
            //Wystepuje bicie
            for (auto &capture : captures){
                this->MakeCapture(capture.from, capture.dest);
                capture.SetScore(this->EvaluateCapture(capture.capturePos));
                Node node = Node(this->boardArray, capture);
                this->tree[i].subtree.push_back(node);
            }
        }
        i++;
    }

    for (int j = 0; j < this->tree.size(); ++j) {
        for (int k = 0; k < this->tree[j].subtree.size(); ++k) {
            this->boardArray = this->tree[j].subtree[k].simulatedBoard;
            captures = this->GetAvalibleCapture(black);

            if(captures.size() == 0){
                //Brak bicia
                movements = this->GetAvaliableChequers(black);

                for (auto &movement : movements){
                    this->MakeMove(movement.from, movement.dest);
                    movement.SetScore(this->EvaluateMove(movement.dest));
                    Node node = Node(this->boardArray, movement);
                    this->tree[j].subtree[k].subtree.push_back(node);
                }
            }else{
                //Wystepuje bicie
                for (auto &capture : captures){
                    this->MakeCapture(capture.from, capture.dest);
                    capture.SetScore(this->EvaluateCapture(capture.capturePos));
                    Node node = Node(this->boardArray, capture);
                    this->tree[j].subtree[k].subtree.push_back(node);
                }
            }
        }
    }
}

void BotController::MakeAction() {

}

