
#ifndef KLONDIKE_EXITCONTROLLERBUILDER_H
#define KLONDIKE_EXITCONTROLLERBUILDER_H

#include "../ActionListController.h"
#include "../GameController.h"

namespace controllers
{
    namespace local
    {
        class ExitControllerBuilder
        {
        public:
            ExitControllerBuilder(controllers::GameController& gameController);
            std::shared_ptr<controllers::ActionListController> getExitController();
        protected:
        private:
            controllers::GameController& gameController_;
        };
    }
}


#endif //KLONDIKE_EXITCONTROLLERBUILDER_H
