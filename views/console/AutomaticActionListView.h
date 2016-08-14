#ifndef KLONDIKE_AUTOMATICACTIONLISTVIEW_H
#define KLONDIKE_AUTOMATICACTIONLISTVIEW_H

#include <iostream>
#include "../../controllers/AutomaticActionListController.h"

namespace views
{
    namespace console
    {
        class AutomaticActionListView
        {
        public:
            void interact(controllers::AutomaticActionListController &controller)
            {
                std::vector<std::shared_ptr<MenuEntry>>& actionList = controller.getActionList();
                HeaderActionListView().show(controller.getHeader());
                printMenu(actionList);
                std::shared_ptr<MenuEntry> entry = controller.getAction();
                std::cout << "Selected action: " << entry->getName() << std::endl;
                entry->doAction();
            }

        protected:
        private:
            void printMenu(std::vector<std::shared_ptr<MenuEntry>>& actionList)
            {
                unsigned int optionIndex = 0;
                for (auto &it : actionList)
                {
                    std::cout << ++optionIndex << ". " << it->getName() << std::endl;
                }
                std::cout << "----------------------------------" << std::endl;
            }
        };
    }
}


#endif //KLONDIKE_AUTOMATICACTIONLISTVIEW_H
