#ifndef KLONDIKE_LOCALUDOREDOCONTROLLER_H
#define KLONDIKE_LOCALUDOREDOCONTROLLER_H

#include <stack>
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
        protected:
            void clearRedoStack();
        private:
            std::stack<std::shared_ptr<KlondikeCommand>> undoStack_;
            std::stack<std::shared_ptr<KlondikeCommand>> redoStack_;
        };
    }
}


#endif //KLONDIKE_LOCALUDOREDOCONTROLLER_H
