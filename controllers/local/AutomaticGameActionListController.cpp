#include "AutomaticGameActionListController.h"
#include "../../utils/RandomSelector.h"
#include "../../models/FoundationToTableauCommand.h"
#include "../../models/StockToWasteCommand.h"
#include "../../models/TableauToFoundationCommand.h"
#include "../../models/TableauToTableauCommand.h"
#include "../../models/WasteToFoundationCommand.h"
#include "../../models/WasteToStockCommand.h"
#include "../../models/WasteToTableauCommand.h"

controllers::local::AutomaticGameActionListController::AutomaticGameActionListController(Game& game) :
game_(game)
{
    setHeader(std::make_shared<GameActionListHeader>(game_));
}
void controllers::local::AutomaticGameActionListController::accept(controllers::OperationControllerVisitor& visitor)
{
    visitor.visit(*this);
}
std::shared_ptr<MenuEntry> controllers::local::AutomaticGameActionListController::getAutomaticAction()
{
    //TODO: algorithm that chooses the action from the list and the game
    std::shared_ptr<MenuEntry> selectedAction = *select_randomly(entryList_.begin(), entryList_.end());
    selectedAction->accept(*this);
    return selectedAction;
}

void controllers::local::AutomaticGameActionListController::visit(FoundationToTableauCommand &command)
{
    randomFillCommand(command);
}

void controllers::local::AutomaticGameActionListController::visit(StockToWasteCommand &command)
{
    randomFillCommand(command);
}

void controllers::local::AutomaticGameActionListController::visit(TableauToFoundationCommand &command)
{
    randomFillCommand(command);
}

void controllers::local::AutomaticGameActionListController::visit(TableauToTableauCommand &command)
{
    randomFillCommand(command);
}

void controllers::local::AutomaticGameActionListController::visit(WasteToFoundationCommand &command)
{
    randomFillCommand(command);
}

void controllers::local::AutomaticGameActionListController::visit(WasteToStockCommand &command)
{
    randomFillCommand(command);
}

void controllers::local::AutomaticGameActionListController::visit(WasteToTableauCommand &command)
{
    randomFillCommand(command);
}

void controllers::local::AutomaticGameActionListController::randomFillCommand(KlondikeCommand &command)
{
    auto originPilesOptions = command.getOriginPiles();
    auto destinyPilesOptions = command.getDestinyPiles();
    auto originPile = *select_randomly(originPilesOptions.begin(), originPilesOptions.end());

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,originPile.size() - 1);

    command.setOriginPile(originPile);
    command.setDestinyPile(*select_randomly(destinyPilesOptions.begin(), destinyPilesOptions.end()));
    command.setCardsToMove(distribution(generator));
}
