#ifndef KLONDIKE_UNDOGAMEACTION_H
#define KLONDIKE_UNDOGAMEACTION_H

#include "../../utils/MenuEntry.h"
#include "../../models/KlondikeCommand.h"
#include "../UndoRedoController.h"
#include <memory>

namespace controllers
{
    namespace local
    {
        class UndoGameAction : public MenuEntry
        {
        public:
            UndoGameAction(std::shared_ptr<controllers::UndoRedoController> undoRedoController);
            void doAction();
            void accept(MenuEntryVisitor &menuEntryVisitor);

        protected:
        private:
            std::shared_ptr<controllers::UndoRedoController> undoRedoController_;
        };
    }
}



#endif //KLONDIKE_UNDOGAMEACTION_H
