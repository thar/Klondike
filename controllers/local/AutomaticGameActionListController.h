#ifndef KLONDIKE_AUTOMATICGAMEACTIONLISTCONTROLLER_H
#define KLONDIKE_AUTOMATICGAMEACTIONLISTCONTROLLER_H

#include "../AutomaticActionListController.h"
#include "GameActionListHeader.h"


namespace controllers
{
    namespace local
    {
        class AutomaticGameActionListController : public controllers::AutomaticActionListController
        {
        public:
            AutomaticGameActionListController(Game& game);
            std::vector<std::shared_ptr<MenuEntry>>& getActionList();
            void addAction(std::shared_ptr<MenuEntry> action);
            void accept(controllers::OperationControllerVisitor& visitor);
            std::shared_ptr<MenuEntry> getAction();
            ActionListHeader& getHeader();
        protected:
        private:
            std::vector<std::shared_ptr<MenuEntry>> actionList_;
            Game& game_;
            GameActionListHeader gameActionListHeader_;
        };
    }
}


#endif //KLONDIKE_AUTOMATICGAMEACTIONLISTCONTROLLER_H
