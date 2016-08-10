#ifndef KLONDIKE_LOCALPLAYERSELECTIONCONTROLLER_H
#define KLONDIKE_LOCALPLAYERSELECTIONCONTROLLER_H


#include "../ConfigurationController.h"
#include "../OperationControllerVisitor.h"
#include "../PlayerSeleccionController.h"

namespace controllers
{
    namespace local
    {
        class LocalPlayerSelectionController : public PlayerSeleccionController
        {
        public:
            LocalPlayerSelectionController(ConfigurationController& configurationController)
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
            ConfigurationController& configurationController_;

        };
    }
}


#endif //KLONDIKE_LOCALPLAYERSELECTIONCONTROLLER_H
