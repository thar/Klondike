#include "ActionListView.h"


void views::console::ActionListView::interact(controllers::ActionListController &controller)
{
    HeaderActionListView().show(controller.getHeader());
    std::shared_ptr<MenuEntry> entry = getUserInput(controller);
    entry->accept(*this);
    entry->doAction();
}
void views::console::ActionListView::automaticInteract(controllers::ActionListController &controller)
{
    HeaderActionListView().show(controller.getHeader());
    printMenu(controller);
    std::shared_ptr<MenuEntry> entry = controller.getAutomaticAction();
    std::cout << "Selected action: " << entry->getName() << std::endl;
    entry->doAction();
}
void views::console::ActionListView::printMenu(controllers::ActionListController &controller)
{
    unsigned int optionIndex = 0;
    for (auto &it : controller)
    {
        std::cout << ++optionIndex << ". " << it->getName() << std::endl;
    }
    std::cout << "----------------------------------" << std::endl;
}
std::shared_ptr<MenuEntry> views::console::ActionListView::getUserInput(controllers::ActionListController &controller)
{
    auto size = controller.end() - controller.begin();
    unsigned int option = 1;
    do
    {
        if (0 >= option || size < option)
            std::cout << "Please, chose an option in range" << std::endl;
        printMenu(controller);
        std::cout << "Option? [1-" << size << "]: " << std::endl;
        std::cin >> option;
    } while (0 >= option || size < option);
    return *(controller.begin() + (option - 1));
}
