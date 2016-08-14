#include "ActionListView.h"


void views::console::ActionListView::interact(controllers::ActionListController &controller)
{
    std::vector<std::shared_ptr<MenuEntry>>& actionList = controller.getActionList();
    HeaderActionListView().show(controller.getHeader());
    std::shared_ptr<MenuEntry> entry = getUserInput(actionList);
    entry->accept(*this);
    entry->doAction();
}
void views::console::ActionListView::printMenu(std::vector<std::shared_ptr<MenuEntry>>& actionList)
{
    unsigned int optionIndex = 0;
    for (auto &it : actionList)
    {
        std::cout << ++optionIndex << ". " << it->getName() << std::endl;
    }
    std::cout << "----------------------------------" << std::endl;
}
std::shared_ptr<MenuEntry> views::console::ActionListView::getUserInput(std::vector<std::shared_ptr<MenuEntry>>& actionList)
{
    unsigned int option = 1;
    do
    {
        if (0 >= option || actionList.size() < option)
            std::cout << "Please, chose an option in range" << std::endl;
        printMenu(actionList);
        std::cout << "Option? [1-" << actionList.size() << "]: " << std::endl;
        std::cin >> option;
    } while (0 >= option || actionList.size() < option);
    return actionList[option - 1];
}
