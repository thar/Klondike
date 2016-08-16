#ifndef KLONDIKE_LOCALACTIONLISTCONTROLLER_H
#define KLONDIKE_LOCALACTIONLISTCONTROLLER_H


#include "../ActionListController.h"

namespace controllers
{
    namespace local
    {
        class LocalActionListController : public ActionListController
        {
        public:
            LocalActionListController();
            void addAction(std::shared_ptr<MenuEntry> action);
            ActionListHeader& getHeader();
            void setHeader(std::shared_ptr<ActionListHeader> header);

            iterator begin();
            iterator end();
        protected:
            ActionList entryList_;
            std::shared_ptr<ActionListHeader> actionListHeader_;
        private:
        };
    }
}


#endif //KLONDIKE_LOCALACTIONLISTCONTROLLER_H
