#ifndef KLONDIKE_GAMEACTIONSCONTROLLERBUILDER_H
#define KLONDIKE_GAMEACTIONSCONTROLLERBUILDER_H

#include "../ActionListController.h"
#include "../UndoRedoController.h"
#include "../GameController.h"
#include "../../models/Game.h"

namespace controllers
{
    namespace local
    {
        class GameActionsControllerBuilder
        {
        public:
            GameActionsControllerBuilder(Game& game, GameController& gameController);
            std::shared_ptr<controllers::ActionListController> getGameActionsController(PlayerType playerType);
        protected:
            void addKlondikeCommandGameActions(controllers::ActionListController& gameActionsController, std::shared_ptr<UndoRedoController> undoRedoController);
        private:
            Game& game_;
            GameController& gameController_;
        };
    }
}


#endif //KLONDIKE_GAMEACTIONSCONTROLLERBUILDER_H
