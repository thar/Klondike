#ifndef KLONDIKE_NEWGAMEVIEW_H
#define KLONDIKE_NEWGAMEVIEW_H

#include <iostream>
#include "../../controllers/NewGameController.h"

namespace views
{
    namespace console
    {
        class NewGameView
        {
        public:
            void interact(controllers::NewGameController &controller)
            {
                unsigned int userChoose = 0;
                do
                {
                    std::cout << "Choose new game or load" << std::endl;
                    std::cout << "1. New game" << std::endl << "2. Load game" << std::endl;

                    std::cin >> userChoose;
                } while (userChoose < 1 || userChoose > 2);
                if (userChoose == 1)
                {
                    controller.setNewGame();
                }
                else
                {
                    controller.setLoadGame();
                }
            }
        };
    }
}


#endif //KLONDIKE_NEWGAMEVIEW_H
