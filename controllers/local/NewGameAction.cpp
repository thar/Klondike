
#include "NewGameAction.h"

controllers::local::NewGameAction::NewGameAction(controllers::GameController &controller) :
        MenuEntry("New game"), controller_(controller)
{

}

void controllers::local::NewGameAction::doAction()
{
    controller_.newGame();
}

void controllers::local::NewGameAction::accept(MenuEntryVisitor &menuEntryVisitor)
{

}
