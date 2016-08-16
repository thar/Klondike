#include "LocalActionListController.h"

controllers::local::LocalActionListController::LocalActionListController()
        : actionListHeader_(nullptr)
{}
ActionList& controllers::local::LocalActionListController::getActionList()
{
    return entryList_;
}
void controllers::local::LocalActionListController::addAction(std::shared_ptr<MenuEntry> action)
{
    entryList_.push_back(action);
}
controllers::ActionListHeader& controllers::local::LocalActionListController::getHeader()
{
    return *actionListHeader_;
}
void controllers::local::LocalActionListController::setHeader(std::shared_ptr<controllers::ActionListHeader> header)
{
    actionListHeader_ = header;
}
controllers::local::LocalActionListController::iterator controllers::local::LocalActionListController::begin()
{
    return entryList_.begin();
}
controllers::local::LocalActionListController::iterator controllers::local::LocalActionListController::end()
{
    return entryList_.end();
}