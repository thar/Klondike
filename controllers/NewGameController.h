#ifndef KLONDIKE_NEWGAMECONTROLLER_H
#define KLONDIKE_NEWGAMECONTROLLER_H

#include "OperationController.h"
#include "PlayerController.h"

namespace controllers
{
    class NewGameController : public OperationController
    {
    public:
        NewGameController(PlayerController &playerController)
                : playerController_(playerController)
        {
        }

        void accept(OperationControllerVisitor &operationControllerVisitor)
        {
            operationControllerVisitor.visit(*this);
        }

        void setLoadGame()
        {
            playerController_.setLoadGame();
        }

        void setNewGame()
        {
            playerController_.setNewGame();
        }

    protected:
    private:
        PlayerController& playerController_;

    };
}


#endif //KLONDIKE_NEWGAMECONTROLLER_H
