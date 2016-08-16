#ifndef KLONDIKE_KLONDIKECOMMANDGAMEACTION_H
#define KLONDIKE_KLONDIKECOMMANDGAMEACTION_H

#include <string>
#include <stack>
#include "../../models/KlondikeCommand.h"
#include "MenuEntryVisitor.h"
#include "../../utils/MenuEntry.h"
#include "../UndoRedoController.h"

namespace controllers
{
    namespace local
    {
        class KlondikeCommandGameAction : public MenuEntry
        {
        public:
            KlondikeCommandGameAction(std::string gameActionName, std::shared_ptr<KlondikeCommand> gameCommand,
                                      std::shared_ptr<controllers::UndoRedoController> undoRedoController);
            void init();
            void doAction();
            void accept(MenuEntryVisitor &menuEntryVisitor);
            void accept(KlondikeCommandVisitor& visitor);

        protected:
        private:
            std::shared_ptr<KlondikeCommand> gameCommandPrototype_;
            std::shared_ptr<KlondikeCommand> gameCommand_;
            std::shared_ptr<controllers::UndoRedoController> undoRedoController_;

        };
    }
}


#endif //KLONDIKE_KLONDIKECOMMANDGAMEACTION_H
