#ifndef KLONDIKE_DECKSELECTIONVIEW_H
#define KLONDIKE_DECKSELECTIONVIEW_H

#include <iostream>
#include "../../controllers/ChooseDeckController.h"

namespace views
{
    namespace console
    {
        class DeckSelectionView
        {
        public:
            void interact(controllers::ChooseDeckController &controller)
            {
                unsigned int userChoose = 0;
                do
                {
                    std::cout << "Choose deck" << std::endl;
                    std::cout << "1. Spanish" << std::endl << "2. French" << std::endl;

                    std::cin >> userChoose;
                } while (userChoose < 1 || userChoose > 2);
                std::string choosedDeck;
                if (userChoose == 1)
                {
                    choosedDeck = "config/decks/spanishDeck.txt";
                }
                else
                {
                    choosedDeck = "config/decks/frenchDeck.txt";
                }
                controller.setDeck(choosedDeck);
            }
        protected:
        private:
        };
    }
}

#endif //KLONDIKE_DECKSELECTIONVIEW_H
