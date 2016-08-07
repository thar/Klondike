#ifndef KLONDIKE_LOCALEXITGAMECONTROLLER_H
#define KLONDIKE_LOCALEXITGAMECONTROLLER_H

#include "ConfigurationController.h"
#include "../ExitGameController.h"

namespace controllers
{
    namespace local
    {
        class LocalExitGameController : public ExitGameController
        {
        public:
            LocalExitGameController(LocalConfigurationController& configurationController) :
                    configurationController_(configurationController)
            {}

            void setContinueGame()
            {
                configurationController_.setContinueGame();
            }

            void setExitGame()
            {
                configurationController_.setExitGame();
            }

            void accept(OperationControllerVisitor& operationControllerVisitor)
            {
                operationControllerVisitor.visit(*this);
            }

        protected:
        private:
            LocalConfigurationController& configurationController_;
        };
    }
}


#endif //KLONDIKE_LOCALEXITGAMECONTROLLER_H
