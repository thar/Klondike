#ifndef KLONDIKE_CHOOSEDECKCONTROLLER_H
#define KLONDIKE_CHOOSEDECKCONTROLLER_H

#include "OperationController.h"
#include "PlayerController.h"
#include "../models/Game.h"
#include "ConfigurationController.h"
#include "GameActionController.h"
#include <memory>

namespace controllers
{
    class ChooseDeckController : public OperationController
    {
    public:
        ChooseDeckController(PlayerController& player)
                : player_(player)
        {
        }

        void accept(OperationControllerVisitor &operationControllerVisitor)
        {
            operationControllerVisitor.visit(*this);
        }

        PlayerController& getPlayer() { return player_; }

    protected:
    private:
        PlayerController& player_;

    };
}


#endif //KLONDIKE_CHOOSEDECKCONTROLLER_H
