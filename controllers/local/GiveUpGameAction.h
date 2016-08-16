#ifndef KLONDIKE_GIVEUPGAMEACTION_H
#define KLONDIKE_GIVEUPGAMEACTION_H

#include "../../utils/MenuEntry.h"
#include "../GameController.h"

namespace controllers
{
    namespace local
    {
        class GiveUpGameAction : public MenuEntry
        {
        public:
            GiveUpGameAction(controllers::GameController& controller);
            void doAction();
            void accept(MenuEntryVisitor &menuEntryVisitor);
        protected:
        private:
            controllers::GameController& controller_;
        };
    }
}



#endif //KLONDIKE_GIVEUPGAMEACTION_H
