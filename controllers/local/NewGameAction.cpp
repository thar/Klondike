
#include <Localization.h>
#include "NewGameAction.h"

controllers::local::NewGameAction::NewGameAction(controllers::GameController &controller) :
        MenuEntry(Localization::getInstance().getValue(localization::NEW_GAME)), controller_(controller)
{

}

void controllers::local::NewGameAction::doAction()
{
    controller_.newGame();
}

void controllers::local::NewGameAction::accept(MenuEntryVisitor &menuEntryVisitor)
{

}
