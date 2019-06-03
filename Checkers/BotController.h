//
// Created by Wojciech Konury on 02/06/2019.
//

#ifndef CHECKERS_BOTCONTROLLER_H
#define CHECKERS_BOTCONTROLLER_H


#include "BoardController.h"
#include "Node.h"
#include <iostream>

class BotController : public BoardController {
private:
    std::vector<Node> tree;

    int EvaluateMove(Cell dest);
    int EvaluateCapture(Cell capturePos);

public:
    void ReadBoard(std::vector<std::vector<Cell>> gameBoard);

    void MakeTree();
    Node MakeAction();

    void Hide(int x, int y) override;
    void Show(int x, int y, ChequerRep chequer) override;
    Color SwitchTurn() override;
};


#endif //CHECKERS_BOTCONTROLLER_H
