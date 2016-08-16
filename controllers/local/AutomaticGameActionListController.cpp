#include "AutomaticGameActionListController.h"


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
    //algorithm that chooses the action from the list and the game
    std::shared_ptr<MenuEntry> selectedAction = entryList_[0];
    selectedAction->accept(*this);
    return entryList_[0];
}