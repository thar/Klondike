#include "AutomaticDeckActionListController.h"

#include "../OperationControllerVisitor.h"


controllers::local::AutomaticDeckActionListController::AutomaticDeckActionListController() :
deckActionListHeader_("Select Deck")
{}
std::vector<std::shared_ptr<MenuEntry>>& controllers::local::AutomaticDeckActionListController::getActionList()
{
    return actionList_;
}
void controllers::local::AutomaticDeckActionListController::addAction(std::shared_ptr<MenuEntry> action)
{
    actionList_.push_back(action);
}
void controllers::local::AutomaticDeckActionListController::accept(controllers::OperationControllerVisitor& visitor)
{
    visitor.visit(*this);
}
std::shared_ptr<MenuEntry> controllers::local::AutomaticDeckActionListController::getAction()
{
    return actionList_[0];
}
controllers::ActionListHeader& controllers::local::AutomaticDeckActionListController::getHeader()
{
    return deckActionListHeader_;
}