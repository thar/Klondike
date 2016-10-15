
#include "GameFromFileAction.h"
#include "LocalGameSaver.h"

controllers::local::GameFromFileAction::GameFromFileAction(std::string filePath, controllers::GameController &controller) :
        MenuEntry(filePath.substr(filePath.find_last_of("/") + 1)), filePath_(filePath), controller_(controller)
{

}

void controllers::local::GameFromFileAction::doAction()
{
    LocalGameSaver gameSaver(filePath_);
    gameSaver.load();
    controller_.restore(gameSaver);
}

void controllers::local::GameFromFileAction::accept(MenuEntryVisitor &menuEntryVisitor)
{

}
