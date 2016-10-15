#include "LoadGameControllerBuilder.h"
#include "UserActionListController.h"
#include "StringActionListHeader.h"
#include "GameFromFileAction.h"
#include "pathUtils.h"

controllers::local::LoadGameControllerBuilder::LoadGameControllerBuilder(controllers::GameController &gameController) :
    gameController_(gameController)
{

}

std::shared_ptr<controllers::ActionListController> controllers::local::LoadGameControllerBuilder::getLoadController()
{
    std::shared_ptr<controllers::ActionListController> loadController =
            std::make_shared<controllers::local::UserActionListController>();
    loadController->setHeader(std::make_shared<StringActionListHeader>("Choose file"));
    auto existingFiles = globVector("savedGames/*");
    for (auto& file : existingFiles)
    {
        loadController->addAction(std::make_shared<GameFromFileAction>(file, gameController_));
    }
    return loadController;
}
