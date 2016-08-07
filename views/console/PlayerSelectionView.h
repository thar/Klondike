#ifndef KLONDIKE_PLAYERSELECTIONVIEW_H
#define KLONDIKE_PLAYERSELECTIONVIEW_H

#include <iostream>
#include "../../controllers/PlayerSeleccionController.h"

namespace views
{
    namespace console
    {
        class PlayerSelectionView
        {
        public:
            void interact(controllers::PlayerSeleccionController &controller)
            {
                unsigned int userType = 0;
                do
                {
                    std::cout << "Choose player" << std::endl;
                    std::cout << "1. User" << std::endl << "2. Demo" << std::endl;

                    std::cin >> userType;
                } while (userType < 1 || userType > 2);
                if (userType == 1)
                {
                    controller.selectPlayer(::controllers::PlayerType::USER);
                }
                else
                {
                    controller.selectPlayer(::controllers::PlayerType::DEMO);
                }
            }
        protected:
        private:
        };
    }
}


#endif //KLONDIKE_PLAYERSELECTIONVIEW_H
