#include "ActionListView.h"
#include "Localization.h"
#include "../../controllers/local/SaveGameAction.h"

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
    std::cout << Localization::getInstance().getValue(localization::SELECTED_ACTION) << entry->getName() << std::endl;
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
            std::cout << Localization::getInstance().getValue(localization::OPTION_IN_RANGE) << std::endl;
        printMenu(controller);
        std::cout << Localization::getInstance().getValue(localization::OPTION) << "? [1-" << size << "]: " << std::endl;
        std::cin >> option;
    } while (0 >= option || size < option);
    return *(controller.begin() + (option - 1));
}

void views::console::ActionListView::visit(controllers::local::SaveGameAction &entry)
{
    std::string fileName;
    bool fileNameStored;
    do
    {
        std::cout << Localization::getInstance().getValue(localization::FILE_NAME) << ": " << std::endl;
        std::cin >> fileName;
        fileNameStored = entry.setFileName(fileName, false);
        if (!fileNameStored)
        {
            std::cout << Localization::getInstance().getValue(localization::FILE_EXISTS) << std::endl;
            int option = 0;
            do
            {
                if (0 >= option || 2 < option)
                    std::cout << Localization::getInstance().getValue(localization::OPTION_IN_RANGE) << std::endl;
                std::cout << "1 ->" << Localization::getInstance().getValue(localization::NEW_FILE_NAME) << std::endl;
                std::cout << "2 ->" << Localization::getInstance().getValue(localization::FILE_OVERWRITE) << std::endl;
                std::cin >> option;
            } while (0 >= option || 2 < option);
            if (option == 2)
            {
                fileNameStored = entry.setFileName(fileName, true);
            }
        }
    } while(!fileNameStored);
}
