#ifndef KLONDIKE_LOCALUDOREDOCONTROLLER_H
#define KLONDIKE_LOCALUDOREDOCONTROLLER_H

#include <list>
#include "../UndoRedoController.h"

namespace controllers
{
    namespace local
    {
        class LocalUndoRedoController : public controllers::UndoRedoController
        {
        public:
            void undo();
            void redo();
            void addCommand(std::shared_ptr<KlondikeCommand>);
            void saveUndoList(GameSaver& undoListSaver);
        protected:
            void clearRedoStack();
        private:
            std::list<std::shared_ptr<KlondikeCommand>> undoStack_;
            std::list<std::shared_ptr<KlondikeCommand>> redoStack_;
        };
    }
}


#endif //KLONDIKE_LOCALUDOREDOCONTROLLER_H
