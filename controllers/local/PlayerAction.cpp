#include "PlayerAction.h"

controllers::local::PlayerAction::PlayerAction(controllers::GameController& gameController,
                                           PlayerType playerType) :
        MenuEntry(playerType == USER ? "User" : "Demo"), gameController_(gameController), playerType_(playerType)
{}

void controllers::local::PlayerAction::doAction()
{
    gameController_.setPlayer(playerType_);
}

void controllers::local::PlayerAction::accept(MenuEntryVisitor &menuEntryVisitor)
{}