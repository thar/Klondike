#ifndef KLONDIKE_UNDOREDOCONTROLLER_H
#define KLONDIKE_UNDOREDOCONTROLLER_H

#include <memory>
#include "GameSaver.h"
#include "../models/KlondikeCommand.h"

namespace controllers
{
    class UndoRedoController
    {
    public:
        virtual void undo() = 0;
        virtual void redo() = 0;
        virtual void addCommand(std::shared_ptr<KlondikeCommand>) = 0;
        virtual void saveUndoList(GameSaver& gameSaver) = 0;
    protected:
    private:
    };
}

#endif //KLONDIKE_UNDOREDOCONTROLLER_H
