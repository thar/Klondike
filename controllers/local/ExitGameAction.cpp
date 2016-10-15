#include <Localization.h>
#include "ExitGameAction.h"

controllers::local::ExitGameAction::ExitGameAction(controllers::GameController& controller) :
MenuEntry(Localization::getInstance().getValue(localization::EXIT_GAME)), controller_(controller)
        {}
void controllers::local::ExitGameAction::doAction() { controller_.exitGame(); }
void controllers::local::ExitGameAction::accept(MenuEntryVisitor &menuEntryVisitor) {}