
#include <Localization.h>
#include "RestartGameAction.h"

controllers::local::RestartGameAction::RestartGameAction(controllers::GameController &controller) :
        MenuEntry(Localization::getInstance().getValue(localization::RESTART_GAME)), controller_(controller)
{

}

void controllers::local::RestartGameAction::doAction()
{
    controller_.restart();
}

void controllers::local::RestartGameAction::accept(MenuEntryVisitor &menuEntryVisitor)
{

}
