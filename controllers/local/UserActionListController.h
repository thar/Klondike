#ifndef KLONDIKE_USERACTIONLISTCONTROLLER_H
#define KLONDIKE_USERACTIONLISTCONTROLLER_H

#include <memory>
#include <vector>
#include "LocalActionListController.h"

namespace controllers
{
    namespace local
    {
        class UserActionListController : public LocalActionListController
        {
        public:
            std::shared_ptr<MenuEntry> getAutomaticAction();
            void accept(controllers::OperationControllerVisitor& visitor);
        protected:
        private:
        };
    }
}


#endif //KLONDIKE_USERACTIONLISTCONTROLLER_H
