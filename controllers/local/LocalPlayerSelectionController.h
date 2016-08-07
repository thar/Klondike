#ifndef KLONDIKE_LOCALPLAYERSELECTIONCONTROLLER_H
#define KLONDIKE_LOCALPLAYERSELECTIONCONTROLLER_H


#include "ConfigurationController.h"
#include "../OperationControllerVisitor.h"
#include "../PlayerSeleccionController.h"
#include "State.h"

namespace controllers
{
    namespace local
    {
        class LocalPlayerSelectionController : public PlayerSeleccionController
        {
        public:
            LocalPlayerSelectionController(LocalConfigurationController& configurationController)
                    : configurationController_(configurationController)
            {

            }

            void accept(OperationControllerVisitor& operationControllerVisitor) {
                operationControllerVisitor.visit(*this);
            }

            void selectPlayer(::controllers::PlayerType player)
            {
                configurationController_.initDemoPlayer(::controllers::PlayerType::DEMO == player);
            }

        protected:
        private:
            LocalConfigurationController& configurationController_;

        };
    }
}


#endif //KLONDIKE_LOCALPLAYERSELECTIONCONTROLLER_H
