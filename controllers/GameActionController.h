#ifndef KLONDIKE_GAMEACTIONCONTROLLER_H
#define KLONDIKE_GAMEACTIONCONTROLLER_H

#include "OperationController.h"
#include "OperationControllerVisitor.h"
#include "../models/Game.h"
#include "PlayerController.h"

namespace controllers
{
    class GameActionController : public OperationController
    {
    public:

        void accept(OperationControllerVisitor& operationControllerVisitor)
        {
            operationControllerVisitor.visit(*this);
        }

        virtual Game& getGame() const = 0;
        virtual std::shared_ptr<KlondikeCommand> getKlondikeCommand(unsigned int index) = 0;
        virtual void newGame(std::string deckPath) = 0;
        virtual std::shared_ptr<PlayerController> getPlayerController() = 0;

    protected:
    private:
    };
}


#endif //KLONDIKE_GAMEACTIONCONTROLLER_H
