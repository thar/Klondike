
#include <Localization.h>
#include "SaveGameAction.h"
#include "MenuEntryVisitor.h"
#include "LocalUndoListSaver.h"

std::string controllers::local::SaveGameAction::gamesFolder("savedGames/");

controllers::local::SaveGameAction::SaveGameAction(std::shared_ptr<controllers::UndoRedoController> undoRedoController) :
        MenuEntry(Localization::getInstance().getValue(localization::SAVE_GAME)), undoRedoController_(undoRedoController)
{

}

void controllers::local::SaveGameAction::doAction()
{
    LocalUndoListSaver saver(gamesFolder + fileName_);
    undoRedoController_->saveUndoList(saver);
}

void controllers::local::SaveGameAction::accept(MenuEntryVisitor &menuEntryVisitor)
{
    if (fileName_ == "")
        menuEntryVisitor.visit(*this);
}

bool controllers::local::SaveGameAction::setFileName(std::string fileName, bool overwrite)
{
    //check if file exists
    fileName_ = fileName;
    return true;
}
