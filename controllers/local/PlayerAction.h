#ifndef KLONDIKE_PLAYERACTION_H
#define KLONDIKE_PLAYERACTION_H

#include "../GameController.h"
#include "../PlayerType.h"
#include "MenuEntryVisitor.h"
#include "../../utils/MenuEntry.h"

namespace controllers
{
    namespace local
    {
        class PlayerAction : public MenuEntry
        {
        public:
            PlayerAction(controllers::GameController& gameController, PlayerType playerType);
            void doAction();
            void accept(MenuEntryVisitor &menuEntryVisitor);
        protected:
        private:
            controllers::GameController& gameController_;
            PlayerType playerType_;
        };
    }
}


#endif //KLONDIKE_PLAYERACTION_H
