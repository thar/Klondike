#include "RedoGameAction.h"

controllers::local::RedoGameAction::RedoGameAction(std::shared_ptr<controllers::UndoRedoController> undoRedoController) :
MenuEntry("Redo movement"), undoRedoController_(undoRedoController)
        {}
void controllers::local::RedoGameAction::doAction() { undoRedoController_->redo(); }
void controllers::local::RedoGameAction::accept(MenuEntryVisitor &menuEntryVisitor) {}