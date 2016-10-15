
#ifndef KLONDIKE_GAMEFROMFILEACTION_H
#define KLONDIKE_GAMEFROMFILEACTION_H

#include "../../utils/MenuEntry.h"
#include "../GameController.h"

namespace controllers
{
    namespace local
    {
        class GameFromFileAction : public MenuEntry
        {
        public:
            GameFromFileAction(std::string filePath, controllers::GameController& controller);
            void doAction();
            void accept(MenuEntryVisitor &menuEntryVisitor);
        protected:
        private:
            std::string filePath_;
            controllers::GameController& controller_;
        };
    }
}


#endif //KLONDIKE_GAMEFROMFILEACTION_H
