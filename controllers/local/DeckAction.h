#ifndef KLONDIKE_DECKACTION_H
#define KLONDIKE_DECKACTION_H

#include "../GameController.h"
#include "MenuEntryVisitor.h"
#include "../../utils/MenuEntry.h"

namespace controllers
{
    namespace local
    {
        class DeckAction : public MenuEntry
        {
        public:
            DeckAction(controllers::GameController& gameController, std::string deckName, std::string deckPath);
            void doAction();
            void accept(MenuEntryVisitor &menuEntryVisitor);
        protected:
        private:
            std::string deckPath_;
            controllers::GameController& gameController_;
        };
    }
}


#endif //KLONDIKE_DECKACTION_H
