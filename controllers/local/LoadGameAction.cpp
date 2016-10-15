
#include "LoadGameAction.h"

controllers::local::LoadGameAction::LoadGameAction(controllers::GameController &controller) :
        MenuEntry("Load game"), controller_(controller)
{

}

void controllers::local::LoadGameAction::doAction()
{
    controller_.loadGame();
}

void controllers::local::LoadGameAction::accept(MenuEntryVisitor &menuEntryVisitor)
{

}
