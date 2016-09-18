#include "GameActionsControllerBuilder.h"

#include "KlondikeCommandGameAction.h"
#include "StringActionListHeader.h"
#include "UserActionListController.h"
#include "AutomaticGameActionListController.h"
#include "LocalUndoRedoController.h"

#include "UndoGameAction.h"
#include "RedoGameAction.h"
#include "ExitGameAction.h"
#include "GiveUpGameAction.h"

#include "Localization.h"

controllers::local::GameActionsControllerBuilder::GameActionsControllerBuilder(Game& game, GameController& gameController)
 : game_(game), gameController_(gameController)
{}

std::shared_ptr<controllers::ActionListController> controllers::local::GameActionsControllerBuilder::getGameActionsController(PlayerType playerType)
{
    std::shared_ptr<controllers::ActionListController> gameActionsController;
    switch (playerType)
    {
        case USER:
            gameActionsController =
                    std::make_shared<controllers::local::UserActionListController>();
            gameActionsController->setHeader(std::make_shared<GameActionListHeader>(game_));
            break;
        case DEMO:
            gameActionsController = std::make_shared<controllers::local::AutomaticGameActionListController>(game_);
            break;
        default:
            return nullptr;
    }
    std::shared_ptr<UndoRedoController> undoRedoController = std::make_shared<LocalUndoRedoController>();
    addKlondikeCommandGameActions(*gameActionsController, undoRedoController);
    if(USER == playerType)
    {
        gameActionsController->addAction(std::make_shared<UndoGameAction>(undoRedoController));
        gameActionsController->addAction(std::make_shared<RedoGameAction>(undoRedoController));

        gameActionsController->addAction(std::make_shared<GiveUpGameAction>(gameController_));
        gameActionsController->addAction(std::make_shared<ExitGameAction>(gameController_));
    }
    return gameActionsController;
}

void controllers::local::GameActionsControllerBuilder::addKlondikeCommandGameActions(controllers::ActionListController& gameActionsController,
                                                                                     std::shared_ptr<UndoRedoController> undoRedoController)
{
    gameActionsController.addAction(
            std::make_shared<KlondikeCommandGameAction>(
                    Localization::getInstance().getValue(localization::MOVE_FROM) + " " +
                            Localization::getInstance().getValue(localization::STOCK) + " " +
                            Localization::getInstance().getValue(localization::MOVE_TO) + " " +
                            Localization::getInstance().getValue(localization::WAIST), game_.getCommand(0),
                                                        undoRedoController));
    gameActionsController.addAction(
            std::make_shared<KlondikeCommandGameAction>(
                    Localization::getInstance().getValue(localization::MOVE_FROM) + " " +
                    Localization::getInstance().getValue(localization::WAIST) + " " +
                    Localization::getInstance().getValue(localization::MOVE_TO) + " " +
                    Localization::getInstance().getValue(localization::STOCK), game_.getCommand(1),
                                                        undoRedoController));
    gameActionsController.addAction(
            std::make_shared<KlondikeCommandGameAction>(
                    Localization::getInstance().getValue(localization::MOVE_FROM) + " " +
                    Localization::getInstance().getValue(localization::WAIST) + " " +
                    Localization::getInstance().getValue(localization::MOVE_TO) + " " +
                    Localization::getInstance().getValue(localization::FOUNDATION), game_.getCommand(2),
                                                        undoRedoController));
    gameActionsController.addAction(
            std::make_shared<KlondikeCommandGameAction>(
                    Localization::getInstance().getValue(localization::MOVE_FROM) + " " +
                    Localization::getInstance().getValue(localization::WAIST) + " " +
                    Localization::getInstance().getValue(localization::MOVE_TO) + " " +
                    Localization::getInstance().getValue(localization::TABLEAU), game_.getCommand(3),
                                                        undoRedoController));
    gameActionsController.addAction(
            std::make_shared<KlondikeCommandGameAction>(
                    Localization::getInstance().getValue(localization::MOVE_FROM) + " " +
                    Localization::getInstance().getValue(localization::TABLEAU) + " " +
                    Localization::getInstance().getValue(localization::MOVE_TO) + " " +
                    Localization::getInstance().getValue(localization::FOUNDATION), game_.getCommand(4),
                                                        undoRedoController));
    gameActionsController.addAction(
            std::make_shared<KlondikeCommandGameAction>(
                    Localization::getInstance().getValue(localization::MOVE_FROM) + " " +
                    Localization::getInstance().getValue(localization::TABLEAU) + " " +
                    Localization::getInstance().getValue(localization::MOVE_TO) + " " +
                    Localization::getInstance().getValue(localization::TABLEAU), game_.getCommand(5),
                                                        undoRedoController));
    gameActionsController.addAction(
            std::make_shared<KlondikeCommandGameAction>(
                    Localization::getInstance().getValue(localization::MOVE_FROM) + " " +
                    Localization::getInstance().getValue(localization::FOUNDATION) + " " +
                    Localization::getInstance().getValue(localization::MOVE_TO) + " " +
                    Localization::getInstance().getValue(localization::TABLEAU), game_.getCommand(6),
                                                        undoRedoController));
}