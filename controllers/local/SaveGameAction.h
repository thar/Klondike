
#ifndef KLONDIKE_SAVEGAMEACTION_H
#define KLONDIKE_SAVEGAMEACTION_H

#include "../../utils/MenuEntry.h"
#include "../GameController.h"
#include "../UndoRedoController.h"

namespace controllers
{
    namespace local
    {
        class SaveGameAction : public MenuEntry
        {
        public:
            SaveGameAction(GameController& gameController, std::shared_ptr<controllers::UndoRedoController> undoRedoController);
            void doAction();
            void accept(MenuEntryVisitor &menuEntryVisitor);
            bool setFileName(std::string fileName, bool overwrite);
        protected:
        private:
            static std::string gamesFolder;
            std::string fileName_;
            GameController& gameController_;
            std::shared_ptr<controllers::UndoRedoController> undoRedoController_;
        };
    }
}


#endif //KLONDIKE_SAVEGAMEACTION_H
