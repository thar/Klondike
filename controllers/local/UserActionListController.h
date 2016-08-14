#ifndef KLONDIKE_USERACTIONLISTCONTROLLER_H
#define KLONDIKE_USERACTIONLISTCONTROLLER_H

#include <memory>
#include <vector>
#include "../ActionListController.h"
#include "../../utils/MenuEntry.h"

namespace controllers
{
    namespace local
    {
        class UserActionListController : public ActionListController
        {
        public:
            UserActionListController(std::shared_ptr<ActionListHeader> actionListHeader);
            std::vector<std::shared_ptr<MenuEntry>>& getActionList();
            void addAction(std::shared_ptr<MenuEntry> action);
            void accept(controllers::OperationControllerVisitor& visitor);
            ActionListHeader& getHeader();
        protected:
        private:
            std::vector<std::shared_ptr<MenuEntry>> entryList_;
            std::shared_ptr<ActionListHeader> actionListHeader_;
        };
    }
}


#endif //KLONDIKE_USERACTIONLISTCONTROLLER_H
