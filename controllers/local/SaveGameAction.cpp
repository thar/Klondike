
#include <Localization.h>
#include "SaveGameAction.h"
#include "MenuEntryVisitor.h"
#include "LocalGameSaver.h"
#include "pathUtils.h"

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
    if (fileExists(gamesFolder + fileName) && !overwrite)
        return false;
    else
    {
        fileName_ = fileName;
        return true;
    }
}
