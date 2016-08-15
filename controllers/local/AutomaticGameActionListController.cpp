#include "AutomaticGameActionListController.h"

controllers::local::AutomaticGameActionListController::AutomaticGameActionListController(Game& game) :
game_(game), gameActionListHeader_(game)
{}
std::vector<std::shared_ptr<MenuEntry>>& controllers::local::AutomaticGameActionListController::getActionList()
{
    return actionList_;
}
void controllers::local::AutomaticGameActionListController::addAction(std::shared_ptr<MenuEntry> action)
{
    actionList_.push_back(action);
}
void controllers::local::AutomaticGameActionListController::accept(controllers::OperationControllerVisitor& visitor)
{
    visitor.visit(*this);
}
std::shared_ptr<MenuEntry> controllers::local::AutomaticGameActionListController::getAction()
{
    //algorithm that chooses the action from the list and the game
    return actionList_[0];
}
controllers::ActionListHeader& controllers::local::AutomaticGameActionListController::getHeader()
{
    return gameActionListHeader_;
}