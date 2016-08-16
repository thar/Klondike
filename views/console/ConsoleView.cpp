#include "ConsoleView.h"


void views::console::ConsoleView::interact(controllers::OperationController &operationController)
{
    operationController.accept(*this);
}
void views::console::ConsoleView::visit(controllers::local::UserActionListController& controller)
{
    ActionListView().interact(controller);
}
void views::console::ConsoleView::visit(controllers::local::AutomaticDeckActionListController& controller)
{
    ActionListView().automaticInteract(controller);
}
void views::console::ConsoleView::visit(controllers::local::AutomaticGameActionListController& controller)
{
    ActionListView().automaticInteract(controller);
}