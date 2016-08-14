#ifndef KLONDIKE_AUTOMATICDECKACTIONLISTCONTROLLER_H
#define KLONDIKE_AUTOMATICDECKACTIONLISTCONTROLLER_H

#include "../AutomaticActionListController.h"
#include "StringActionListHeader.h"

namespace controllers
{
    namespace local
    {
        class AutomaticDeckActionListController : public controllers::AutomaticActionListController
        {
        public:
            AutomaticDeckActionListController();
            std::vector<std::shared_ptr<MenuEntry>>& getActionList();
            void addAction(std::shared_ptr<MenuEntry> action);
            void accept(controllers::OperationControllerVisitor& visitor);
            std::shared_ptr<MenuEntry> getAction();
            ActionListHeader& getHeader();
            //std::string getMenuHeader();
        protected:
        private:
            std::vector<std::shared_ptr<MenuEntry>> actionList_;
            StringActionListHeader deckActionListHeader_;
        };
    }
}


#endif //KLONDIKE_AUTOMATICDECKACTIONLISTCONTROLLER_H
