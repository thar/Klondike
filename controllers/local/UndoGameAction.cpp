#include "UndoGameAction.h"
#include "Localization.h"

controllers::local::UndoGameAction::UndoGameAction(std::shared_ptr<controllers::UndoRedoController> undoRedoController) :
MenuEntry(Localization::getInstance().getValue(localization::UNDO_MOVEMENT)), undoRedoController_(undoRedoController)
        {}
void controllers::local::UndoGameAction::doAction() { undoRedoController_->undo(); }
void controllers::local::UndoGameAction::accept(MenuEntryVisitor &menuEntryVisitor) {}