#include <Localization.h>
#include "UserActionListController.h"
#include "StartGameControllerBuilder.h"
#include "LoadGameAction.h"
#include "NewGameAction.h"
#include "StringActionListHeader.h"

controllers::local::StartGameControllerBuilder::StartGameControllerBuilder(controllers::GameController &gameController)
        : gameController_(gameController)
{}

std::shared_ptr<controllers::ActionListController>
controllers::local::StartGameControllerBuilder::getStartGameController()
{
    std::shared_ptr<controllers::ActionListController> startGameController =
            std::make_shared<controllers::local::UserActionListController>();
    startGameController->setHeader(std::make_shared<StringActionListHeader>(Localization::getInstance().getValue(localization::SELECT)));
    startGameController->addAction(std::make_shared<NewGameAction>(gameController_));
    startGameController->addAction(std::make_shared<LoadGameAction>(gameController_));
    return startGameController;

}
