#include "AutomaticDeckActionListController.h"


controllers::local::AutomaticDeckActionListController::AutomaticDeckActionListController()
{
    setHeader(std::make_shared<StringActionListHeader>("Select Deck"));
}

void controllers::local::AutomaticDeckActionListController::accept(controllers::OperationControllerVisitor& visitor)
{
    visitor.visit(*this);
}
std::shared_ptr<MenuEntry> controllers::local::AutomaticDeckActionListController::getAutomaticAction()
{
    return entryList_[0];
}