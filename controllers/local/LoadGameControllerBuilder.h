
#ifndef KLONDIKE_LOADGAMECONTROLLERBUILDER_H
#define KLONDIKE_LOADGAMECONTROLLERBUILDER_H

#include "../GameController.h"
#include "../ActionListController.h"

namespace controllers
{
    namespace local
    {
        class LoadGameControllerBuilder
        {
        public:
            LoadGameControllerBuilder(controllers::GameController& gameController);
            std::shared_ptr<controllers::ActionListController> getLoadController();
        protected:
        private:
            controllers::GameController& gameController_;
        };
    }
}


#endif //KLONDIKE_LOADGAMECONTROLLERBUILDER_H
