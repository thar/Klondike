#include "RedoGameAction.h"
#include "Localization.h"

controllers::local::RedoGameAction::RedoGameAction(std::shared_ptr<controllers::UndoRedoController> undoRedoController) :
MenuEntry(Localization::getInstance().getValue(localization::REDO_MOVEMENT)), undoRedoController_(undoRedoController)
        {}
void controllers::local::RedoGameAction::doAction() { undoRedoController_->redo(); }
void controllers::local::RedoGameAction::accept(MenuEntryVisitor &menuEntryVisitor) {}