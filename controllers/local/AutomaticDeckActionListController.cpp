#include <Localization.h>
#include "AutomaticDeckActionListController.h"
#include "../../utils/RandomSelector.h"


controllers::local::AutomaticDeckActionListController::AutomaticDeckActionListController()
{
    setHeader(std::make_shared<StringActionListHeader>(Localization::getInstance().getValue(localization::SELECT) + " " +
                                                               Localization::getInstance().getValue(localization::DECK)));
}

void controllers::local::AutomaticDeckActionListController::accept(controllers::OperationControllerVisitor& visitor)
{
    visitor.visit(*this);
}
std::shared_ptr<MenuEntry> controllers::local::AutomaticDeckActionListController::getAutomaticAction()
{
    return *select_randomly(entryList_.begin(), entryList_.end());
}