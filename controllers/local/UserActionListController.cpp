#include "UserActionListController.h"
#include "../OperationControllerVisitor.h"

controllers::local::UserActionListController::UserActionListController(std::shared_ptr<controllers::ActionListHeader> actionListHeader)
: actionListHeader_(actionListHeader)
{}
std::vector<std::shared_ptr<MenuEntry>>& controllers::local::UserActionListController::getActionList()
{
    return entryList_;
}
void controllers::local::UserActionListController::addAction(std::shared_ptr<MenuEntry> action)
{
    entryList_.push_back(action);
}
void controllers::local::UserActionListController::accept(controllers::OperationControllerVisitor& visitor)
{
    visitor.visit(*this);
}
controllers::ActionListHeader& controllers::local::UserActionListController::getHeader()
{
    return *actionListHeader_;
}