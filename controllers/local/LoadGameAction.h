
#ifndef KLONDIKE_LOADGAMEACTION_H
#define KLONDIKE_LOADGAMEACTION_H

#include "../../utils/MenuEntry.h"
#include "../GameController.h"

namespace controllers
{
    namespace local
    {
        class LoadGameAction : public MenuEntry
        {
        public:
            LoadGameAction(controllers::GameController& controller);
            void doAction();
            void accept(MenuEntryVisitor &menuEntryVisitor);
        protected:
        private:
            controllers::GameController& controller_;
        };
    }
}


#endif //KLONDIKE_LOADGAMEACTION_H
