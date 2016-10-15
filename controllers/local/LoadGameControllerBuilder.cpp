#include "LoadGameControllerBuilder.h"
#include "UserActionListController.h"
#include "StringActionListHeader.h"
#include "GameFromFileAction.h"

controllers::local::LoadGameControllerBuilder::LoadGameControllerBuilder(controllers::GameController &gameController) :
    gameController_(gameController)
{

}

std::shared_ptr<controllers::ActionListController> controllers::local::LoadGameControllerBuilder::getLoadController()
{
    std::shared_ptr<controllers::ActionListController> loadController =
            std::make_shared<controllers::local::UserActionListController>();
    loadController->setHeader(std::make_shared<StringActionListHeader>("Choose file"));
    loadController->addAction(std::make_shared<GameFromFileAction>("savedGames/test1", gameController_));
    return loadController;
}
