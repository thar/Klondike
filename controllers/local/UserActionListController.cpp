#include "UserActionListController.h"


void controllers::local::UserActionListController::accept(controllers::OperationControllerVisitor& visitor)
{
    visitor.visit(*this);
}
std::shared_ptr<MenuEntry> controllers::local::UserActionListController::getAutomaticAction()
{
    return nullptr;
}