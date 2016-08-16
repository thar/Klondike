#include "GiveUpGameAction.h"

controllers::local::GiveUpGameAction::GiveUpGameAction(controllers::GameController& controller) :
MenuEntry("Give up game"), controller_(controller)
        {}
void controllers::local::GiveUpGameAction::doAction() { controller_.abandonGame(); }
void controllers::local::GiveUpGameAction::accept(MenuEntryVisitor &menuEntryVisitor) {}