#ifndef KLONDIKE_DECKCONTROLLERBUILDER_H
#define KLONDIKE_DECKCONTROLLERBUILDER_H

#include "AutomaticDeckActionListController.h"
#include "../GameController.h"
#include "../PlayerType.h"

namespace controllers
{
    namespace local
    {
        class DeckControllerBuilder
        {
        public:
            DeckControllerBuilder(controllers::GameController& gameController, controllers::PlayerType player);
            std::shared_ptr<controllers::ActionListController> getDeckController();
        protected:
        private:
            controllers::GameController& gameController_;
            controllers::PlayerType player_;
        };
    }
}


#endif //KLONDIKE_DECKCONTROLLERBUILDER_H
