
#include <Localization.h>
#include "LoadGameAction.h"

controllers::local::LoadGameAction::LoadGameAction(controllers::GameController &controller) :
        MenuEntry(Localization::getInstance().getValue(localization::LOAD_GAME)), controller_(controller)
{

}

void controllers::local::LoadGameAction::doAction()
{
    controller_.loadGame();
}

void controllers::local::LoadGameAction::accept(MenuEntryVisitor &menuEntryVisitor)
{

}
