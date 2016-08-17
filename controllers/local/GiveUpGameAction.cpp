#include "GiveUpGameAction.h"
#include "Localization.h"

controllers::local::GiveUpGameAction::GiveUpGameAction(controllers::GameController& controller) :
MenuEntry(Localization::getInstance().getValue(localization::GIVE_UP_GAME)), controller_(controller)
        {}
void controllers::local::GiveUpGameAction::doAction() { controller_.abandonGame(); }
void controllers::local::GiveUpGameAction::accept(MenuEntryVisitor &menuEntryVisitor) {}