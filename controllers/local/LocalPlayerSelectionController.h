#ifndef KLONDIKE_LOCALPLAYERSELECTIONCONTROLLER_H
#define KLONDIKE_LOCALPLAYERSELECTIONCONTROLLER_H


#include "../ConfigurationController.h"
#include "../OperationControllerVisitor.h"
#include "../PlayerSeleccionController.h"
#include "LocalGameActionController.h"

namespace controllers
{
    namespace local
    {
        class LocalPlayerSelectionController : public PlayerSeleccionController
        {
        public:
            LocalPlayerSelectionController(ConfigurationController& configurationController, LocalGameActionController& controller)
                    : configurationController_(configurationController), controller_(controller)
            {

            }

            void accept(OperationControllerVisitor& operationControllerVisitor) {
                operationControllerVisitor.visit(*this);
            }

            void selectPlayer(::controllers::PlayerType player)
            {
                if(::controllers::PlayerType::DEMO == player)
                    configurationController_.setNewGame();
                controller_.initDemoPlayer(::controllers::PlayerType::DEMO == player);
            }

        protected:
        private:
            ConfigurationController& configurationController_;
            LocalGameActionController& controller_;

        };
    }
}


#endif //KLONDIKE_LOCALPLAYERSELECTIONCONTROLLER_H
