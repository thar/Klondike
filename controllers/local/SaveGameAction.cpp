
#include <Localization.h>
#include "SaveGameAction.h"
#include "MenuEntryVisitor.h"
#include "LocalGameSaver.h"

std::string controllers::local::SaveGameAction::gamesFolder("savedGames/");

controllers::local::SaveGameAction::SaveGameAction(GameController& gameController, std::shared_ptr<controllers::UndoRedoController> undoRedoController) :
        MenuEntry(Localization::getInstance().getValue(localization::SAVE_GAME)), gameController_(gameController), undoRedoController_(undoRedoController)
{

}

void controllers::local::SaveGameAction::doAction()
{
    LocalGameSaver saver(gamesFolder + fileName_);
    gameController_.save(saver);
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
