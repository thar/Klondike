#ifndef KLONDIKE_PLAYERCHOOSECONTROLLERBUILDER_H
#define KLONDIKE_PLAYERCHOOSECONTROLLERBUILDER_H

#include "../ActionListController.h"
#include "../GameController.h"

namespace controllers
{
    namespace local
    {
        class PlayerChooseControllerBuilder
        {
        public:
            PlayerChooseControllerBuilder(controllers::GameController& gameController);
            std::shared_ptr<controllers::ActionListController> getPlayerChooseController();
        protected:
        private:
            controllers::GameController& gameController_;
        };
    }
}


#endif //KLONDIKE_PLAYERCHOOSECONTROLLERBUILDER_H
