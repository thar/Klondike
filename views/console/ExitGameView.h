#ifndef KLONDIKE_EXITGAMEVIEW_H
#define KLONDIKE_EXITGAMEVIEW_H

#include <iostream>
#include "../../controllers/ExitGameController.h"

namespace views
{
    namespace console
    {
        class ExitGameView
        {
        public:
            void interact(controllers::ExitGameController &controller)
            {
                unsigned int userInput = 0;
                do
                {
                    std::cout << "Select action" << std::endl;
                    std::cout << "1. New game" << std::endl << "2. Exit game" << std::endl;

                    std::cin >> userInput;
                } while (userInput < 1 || userInput > 2);
                if (1 == userInput)
                {
                    controller.setContinueGame();
                }
                else
                {
                    controller.setExitGame();
                };
            }
        };
    }
}


#endif //KLONDIKE_EXITGAMEVIEW_H
