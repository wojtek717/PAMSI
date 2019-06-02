//
// Created by Wojciech Konury on 02/06/2019.
//

#ifndef CHECKERS_BOARDCONTROLLER_H
#define CHECKERS_BOARDCONTROLLER_H


#include "Cell.h"
#include "Movement.h"
#include "Capture.h"


class BoardController {
protected:

    Cell chosen;
    bool isChosen;

public:
    //Cell boardArray[8][8];
    std::vector<std::vector<Cell>> boardArray;


    Cell GetBoardItem(int x, int y);
    //Cell* GetBoard();

    bool IsMoveAvaliable(Cell from, Cell dest);
    std::vector<Movement> GetAvaliableChequers(Color color);

    Capture IsCaptureAvalible(Cell from, Cell dest);
    std::vector<Capture> GetAvalibleCapture(Color color);

    void MakeMove(Cell from, Cell dest);
    void MakeCapture(Cell from, Cell dest);
    void MakeKing(Cell dest, Color color);

    void SetChosen(int x, int y);
    void SetIsChosen(bool is);
    Cell GetChosen();
    bool IsChosen();

    virtual void Hide(int x, int y) = 0;
    virtual void Show(int x, int y, ChequerRep chequer) = 0;
    virtual Color SwitchTurn() = 0;
};


#endif //CHECKERS_BOARDCONTROLLER_H
