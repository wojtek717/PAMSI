#include <SFML/Graphics.hpp>
#include <string>
#include "Chequer.h"
#include "Cell.h"
#include "GameController.h"




int main() {
    sf::RenderWindow window(sf::VideoMode(8*CELLSIZE,8*CELLSIZE,32),"Checkers");

    GameController gameController;

    //Set Textures
    gameController.SetBoardTexture("Resources/Szachownica.png");
    gameController.SetMansTexture("Resources/PionekW.png", "Resources/PionekW.png");
    gameController.SetKingsTexture("Resources/PionekW.png", "Resources/PionekW.png");

    //Start Game
    gameController.SeedChequers();



    while(window.isOpen()){
        sf::Event event{};

        while(window.pollEvent(event)) {

            if(event.type == sf::Event::Closed){
                window.close();
            }


            // #################################################
            window.draw(gameController.GetBoardSprite());


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