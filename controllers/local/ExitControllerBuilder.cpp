#include <Localization.h>
#include "UserActionListController.h"
#include "ExitControllerBuilder.h"
#include "StringActionListHeader.h"
#include "RestartGameAction.h"
#include "ExitGameAction.h"

controllers::local::ExitControllerBuilder::ExitControllerBuilder(controllers::GameController &gameController)
        : gameController_(gameController)
{}

std::shared_ptr<controllers::ActionListController> controllers::local::ExitControllerBuilder::getExitController()
{
    std::shared_ptr<controllers::ActionListController> exitGameController =
            std::make_shared<controllers::local::UserActionListController>();
    exitGameController->setHeader(std::make_shared<StringActionListHeader>(Localization::getInstance().getValue(localization::SELECT)));
    exitGameController->addAction(std::make_shared<RestartGameAction>(gameController_));
    exitGameController->addAction(std::make_shared<ExitGameAction>(gameController_));
    return exitGameController;
}
