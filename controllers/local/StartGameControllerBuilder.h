
#ifndef KLONDIKE_STARTGAMECONTROLLERBUILDER_H
#define KLONDIKE_STARTGAMECONTROLLERBUILDER_H

#include "../ActionListController.h"
#include "../GameController.h"

namespace controllers
{
    namespace local
    {
        class StartGameControllerBuilder
        {
        public:
            StartGameControllerBuilder(controllers::GameController& gameController);
            std::shared_ptr<controllers::ActionListController> getStartGameController();
        protected:
        private:
            controllers::GameController& gameController_;
        };
    }
}


#endif //KLONDIKE_STARTGAMECONTROLLERBUILDER_H
