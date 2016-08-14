#include "PlayerChooseControllerBuilder.h"

#include "UserActionListController.h"
#include "PlayerAction.h"
#include "StringActionListHeader.h"

controllers::local::PlayerChooseControllerBuilder::PlayerChooseControllerBuilder(controllers::GameController& gameController)
: gameController_(gameController)
{}

std::shared_ptr<controllers::ActionListController> controllers::local::PlayerChooseControllerBuilder::getPlayerChooseController()
{
    std::shared_ptr<controllers::ActionListController> playerChooseController =
            std::make_shared<controllers::local::UserActionListController>(std::make_shared<StringActionListHeader>("Select user"));
    playerChooseController->addAction(std::make_shared<PlayerAction>(gameController_, USER));
    playerChooseController->addAction(std::make_shared<PlayerAction>(gameController_, DEMO));
    return playerChooseController;
}