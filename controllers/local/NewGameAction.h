
#ifndef KLONDIKE_NEWGAMEACTION_H
#define KLONDIKE_NEWGAMEACTION_H

#include "../../utils/MenuEntry.h"
#include "../GameController.h"

namespace controllers
{
    namespace local
    {
        class NewGameAction : public MenuEntry
        {
        public:
            NewGameAction(controllers::GameController& controller);
            void doAction();
            void accept(MenuEntryVisitor &menuEntryVisitor);
        protected:
        private:
            controllers::GameController& controller_;
        };
    }
}


#endif //KLONDIKE_NEWGAMEACTION_H
