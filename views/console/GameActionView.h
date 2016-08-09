#ifndef KLONDIKE_GAMEACTIONVIEW_H
#define KLONDIKE_GAMEACTIONVIEW_H


#include <iostream>
#include "../../controllers/GameActionController.h"

namespace views
{
    namespace console
    {
        class GameActionView
        {
        public:
            void interact(controllers::GameActionController &controller)
            {
                unsigned int action = showMenu();
                switch (action)
                {
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                    case 8:
                        controller.undoMovement();
                        break;
                    case 9:
                        controller.redoMovement();
                        break;
                    case 10:
                        controller.saveGame();
                        break;
                    case 11:
                        controller.giveUpGame();
                        break;
                    case 12:
                        break;
                    default:
                        break;
                }
            }
        protected:
        private:
            unsigned int showMenu()
            {
                unsigned int option = 1;
                do
                {
                    if (0 >= option || 12 < option)
                        std::cout << "Please, chose an option in range" << std::endl;
                    std::cout << "1. Move from Waist to Stock" << std::endl;
                    std::cout << "2. Move from Stock to Waist" << std::endl;
                    std::cout << "3. Move from Waist to Foundation" << std::endl;
                    std::cout << "4. Move from Waist to Tableau" << std::endl;
                    std::cout << "5. Move from Tableau to Foundation" << std::endl;
                    std::cout << "6. Move from Tableau to Tableau" << std::endl;
                    std::cout << "7. Move from Foundation to Tableau" << std::endl;
                    std::cout << "8. Undo movement" << std::endl;
                    std::cout << "9. Redo movement" << std::endl;
                    std::cout << "10. Save game" << std::endl;
                    std::cout << "11. Give up game" << std::endl;
                    std::cout << "12. Exit" << std::endl;
                    std::cout << "----------------------------------" << std::endl;
                    std::cout << "Option? [1-12]: ";
                    std::cin >> option;
                } while (0 >= option || 12 < option);
                return option;
            }
        };
    }
}


#endif //KLONDIKE_GAMEACTIONVIEW_H
