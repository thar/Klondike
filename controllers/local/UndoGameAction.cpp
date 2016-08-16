#include "UndoGameAction.h"

controllers::local::UndoGameAction::UndoGameAction(std::shared_ptr<controllers::UndoRedoController> undoRedoController) :
MenuEntry("Undo movement"), undoRedoController_(undoRedoController)
        {}
void controllers::local::UndoGameAction::doAction() { undoRedoController_->undo(); }
void controllers::local::UndoGameAction::accept(MenuEntryVisitor &menuEntryVisitor) {}