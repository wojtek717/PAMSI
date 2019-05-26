#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "ChequerType.h"
#include "Cell.h"
#include "GameController.h"




int main() {
    sf::RenderWindow window(sf::VideoMode(8*CELLSIZE,8*CELLSIZE,32),"Checkers");

    GameController gameController;
    bool capture;


    //Set Textures
    gameController.SetBoardTexture("Resources/Szachownica.png");
    gameController.SetNoChequerTexture("Resources/PionekNo.png");
    gameController.SetMansTexture("Resources/PionekW.png", "Resources/PionekB.png");
    gameController.SetKingsTexture("Resources/PionekW.png", "Resources/PionekB.png");

    //Start Game
    gameController.SeedChequers();

//temp
    sf::Vector2i v2;

    while(window.isOpen()){
        sf::Event event{};

        while(window.pollEvent(event)) {

            if(event.type == sf::Event::Closed){
                window.close();
            }

            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left ){
                v2 = sf::Mouse::getPosition( window );
                std::cout << "L " << v2.x/110 << " ; " << v2.y/110<< std::endl;

                if(gameController.GetBoardItem(v2.x/110, v2.y/110).isAvaliable()){
                    gameController.SetChosen(v2.x/110, v2.y/110);
                    gameController.SetIsChosen(true);
                }
            }

            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right ){
                v2 = sf::Mouse::getPosition( window );
                std::cout << "R " << v2.x/110 << " ; " << v2.y/110<< std::endl;

                if(gameController.IsChosen() && !capture){
                    if(gameController.IsMoveAvaliable(gameController.GetChosen(), gameController.GetBoardItem(v2.x/CELLSIZE, v2.y/CELLSIZE))){
                        gameController.MakeMove(gameController.GetBoardItem(v2.x/CELLSIZE, v2.y/CELLSIZE));
                    }
                } else if(gameController.IsChosen() && capture){
                    if(gameController.IsCaptureAvalible(gameController.GetChosen(), gameController.GetBoardItem(v2.x/CELLSIZE, v2.y/CELLSIZE))){
                        gameController.MakeCapture(gameController.GetBoardItem(v2.x/CELLSIZE, v2.y/CELLSIZE));
                        std::cout << "I TO JAK";
                    }
                }
            }


            // #################################################
            window.draw(gameController.GetBoardSprite());


//            gameController.GetAvaliableChequers(gameController.GetTurn());

            if(gameController.GetBoardItem(1,4).isChequer() && gameController.GetBoardItem(2,3).isChequer()){
                //std::cout << "Hejo";
            }

            if(!gameController.GetAvalibleCapture(gameController.GetTurn())){
                capture = false;
                gameController.GetAvaliableChequers(gameController.GetTurn());
            } else{
                capture = true;
            }

//            if(gameController.GetTurn() == white){
//                std::cout << "White " << std::endl;
//            } else if (gameController.GetTurn() == black){
//                std::cout << "Black " << std::endl;
//            }

            for (int y = 0; y < 8; ++y) {
                for (int x = 0; x < 8; ++x) {
                    if(gameController.GetBoardItem(x,y).isChequer()){
                        window.draw(gameController.GetBoardItem(x,y).chequerSprite);
                    }
                }
            }

            window.display();
        }
    }

    return 0;

}