#ifndef KLONDIKE_REDOGAMEACTION_H
#define KLONDIKE_REDOGAMEACTION_H

#include "../../utils/MenuEntry.h"
#include "../../models/KlondikeCommand.h"
#include "../UndoRedoController.h"
#include <memory>

class RedoGameAction : public MenuEntry
{
public:
    RedoGameAction(std::shared_ptr<controllers::UndoRedoController> undoRedoController) :
            MenuEntry("Redo movement"), undoRedoController_(undoRedoController)
    {}

    void doAction()
    {
        undoRedoController_->redo();
    }
    void accept(MenuEntryVisitor &menuEntryVisitor) {}

protected:
private:
    std::shared_ptr<controllers::UndoRedoController> undoRedoController_;
};


#endif //KLONDIKE_REDOGAMEACTION_H
