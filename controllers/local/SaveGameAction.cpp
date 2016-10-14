
#include <Localization.h>
#include "SaveGameAction.h"

controllers::local::SaveGameAction::SaveGameAction(Game &game) :
        MenuEntry(Localization::getInstance().getValue(localization::SAVE_GAME)), game_(game)
{

}

void controllers::local::SaveGameAction::doAction()
{

}

void controllers::local::SaveGameAction::accept(MenuEntryVisitor &menuEntryVisitor)
{
}
