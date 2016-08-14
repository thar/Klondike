#ifndef KLONDIKE_ACTIONLISTVIEW_H
#define KLONDIKE_ACTIONLISTVIEW_H

#include <iostream>
#include "../../controllers/ActionListController.h"
#include "../../controllers/local/MenuEntryVisitor.h"
#include "HeaderActionListView.h"

namespace views
{
    namespace console
    {
        class ActionListView : public MenuEntryVisitor
        {
        public:
            void interact(controllers::ActionListController &controller);

        protected:
        private:
            void printMenu(std::vector<std::shared_ptr<MenuEntry>>& actionList);
            std::shared_ptr<MenuEntry> getUserInput(std::vector<std::shared_ptr<MenuEntry>>& actionList);
        };
    }
}

#endif //KLONDIKE_ACTIONLISTVIEW_H
