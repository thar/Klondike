#include "PlayerAction.h"
#include "Localization.h"

controllers::local::PlayerAction::PlayerAction(controllers::GameController& gameController,
                                           PlayerType playerType) :
        MenuEntry(playerType == USER ? Localization::getInstance().getValue(localization::USER) :
                  Localization::getInstance().getValue(localization::DEMO)),
        gameController_(gameController), playerType_(playerType)
{}

void controllers::local::PlayerAction::doAction()
{
    gameController_.setPlayer(playerType_);
}

void controllers::local::PlayerAction::accept(MenuEntryVisitor &menuEntryVisitor)
{}