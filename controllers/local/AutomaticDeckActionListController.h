#ifndef KLONDIKE_AUTOMATICDECKACTIONLISTCONTROLLER_H
#define KLONDIKE_AUTOMATICDECKACTIONLISTCONTROLLER_H

#include "StringActionListHeader.h"
#include "LocalActionListController.h"

namespace controllers
{
    namespace local
    {
        class AutomaticDeckActionListController : public LocalActionListController
        {
        public:
            AutomaticDeckActionListController();
            void accept(controllers::OperationControllerVisitor& visitor);
            std::shared_ptr<MenuEntry> getAutomaticAction();
        protected:
        private:
        };
    }
}


#endif //KLONDIKE_AUTOMATICDECKACTIONLISTCONTROLLER_H
