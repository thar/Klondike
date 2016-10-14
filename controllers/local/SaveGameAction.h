
#ifndef KLONDIKE_SAVEGAMEACTION_H
#define KLONDIKE_SAVEGAMEACTION_H

#include "../../utils/MenuEntry.h"
#include "../GameController.h"
#include "../../models/Game.h"

namespace controllers
{
    namespace local
    {
        class SaveGameAction : public MenuEntry
        {
        public:
            SaveGameAction(Game& game);
            void doAction();
            void accept(MenuEntryVisitor &menuEntryVisitor);
        protected:
        private:
            Game& game_;
        };
    }
}


#endif //KLONDIKE_SAVEGAMEACTION_H
