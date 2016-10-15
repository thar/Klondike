
#ifndef KLONDIKE_RESTARTGAMEACTION_H
#define KLONDIKE_RESTARTGAMEACTION_H

#include "../../utils/MenuEntry.h"
#include "../GameController.h"

namespace controllers
{
    namespace local
    {
        class RestartGameAction : public MenuEntry
        {
        public:
            RestartGameAction(controllers::GameController& controller);
            void doAction();
            void accept(MenuEntryVisitor &menuEntryVisitor);
        protected:
        private:
            controllers::GameController& controller_;
        };
    }
}


#endif //KLONDIKE_RESTARTGAMEACTION_H
