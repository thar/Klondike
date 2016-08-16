#ifndef KLONDIKE_EXITGAMEACTION_H
#define KLONDIKE_EXITGAMEACTION_H

#include "../../utils/MenuEntry.h"
#include "../GameController.h"

namespace controllers
{
    namespace local
    {
        class ExitGameAction : public MenuEntry
        {
        public:
            ExitGameAction(controllers::GameController& controller);
            void doAction();
            void accept(MenuEntryVisitor &menuEntryVisitor);
        protected:
        private:
            controllers::GameController& controller_;
        };
    }
}

#endif //KLONDIKE_EXITGAMEACTION_H
