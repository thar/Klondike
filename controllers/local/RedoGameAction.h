#ifndef KLONDIKE_REDOGAMEACTION_H
#define KLONDIKE_REDOGAMEACTION_H

#include "../../utils/MenuEntry.h"
#include "../../models/KlondikeCommand.h"
#include "../UndoRedoController.h"
#include <memory>

namespace controllers
{
    namespace local
    {
        class RedoGameAction : public MenuEntry
        {
        public:
            RedoGameAction(std::shared_ptr<controllers::UndoRedoController> undoRedoController);
            void doAction();
            void accept(MenuEntryVisitor &menuEntryVisitor);

        protected:
        private:
            std::shared_ptr<controllers::UndoRedoController> undoRedoController_;
        };
    }
}



#endif //KLONDIKE_REDOGAMEACTION_H
