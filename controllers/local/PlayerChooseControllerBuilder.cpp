#include "PlayerChooseControllerBuilder.h"

#include "UserActionListController.h"
#include "PlayerAction.h"
#include "StringActionListHeader.h"

#include "Localization.h"

controllers::local::PlayerChooseControllerBuilder::PlayerChooseControllerBuilder(controllers::GameController& gameController)
: gameController_(gameController)
{}

std::shared_ptr<controllers::ActionListController> controllers::local::PlayerChooseControllerBuilder::getPlayerChooseController()
{
    std::shared_ptr<controllers::ActionListController> playerChooseController =
            std::make_shared<controllers::local::UserActionListController>();
    playerChooseController->setHeader(std::make_shared<StringActionListHeader>(Localization::getInstance().getValue(localization::SELECT) + " " +
                                                                               Localization::getInstance().getValue(localization::PLAYER)));
    playerChooseController->addAction(std::make_shared<PlayerAction>(gameController_, USER));
    playerChooseController->addAction(std::make_shared<PlayerAction>(gameController_, DEMO));
    return playerChooseController;
}