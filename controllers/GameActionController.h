#ifndef KLONDIKE_GAMEACTIONCONTROLLER_H
#define KLONDIKE_GAMEACTIONCONTROLLER_H

#include "OperationController.h"
#include "PlayerController.h"
#include "../models/Game.h"

namespace controllers
{
    class GameActionController : public OperationController
    {
    public:
        GameActionController(PlayerController &playerController, Game &game)
        : playerController_(playerController), game_(game)
                {
                }
        void accept(OperationControllerVisitor& operationControllerVisitor)
        {
            operationControllerVisitor.visit(*this);
        }

        void giveUpGame()
        {
            game_.giveUp();
        }
        void undoMovement()
        {
            playerController_.undoMovement();
        }
        void redoMovement()
        {
            playerController_.redoMovement();
        }
        void saveGame()
        {
            playerController_.saveGame();
        }
        void executeKlondikeCommand(unsigned int action)
        {
            playerController_.executeKlondikeCommand(action);
        }
        Game& getGame() const
        {
            return game_;
        }

    protected:
    private:
        PlayerController& playerController_;
        Game& game_;
    };
}


#endif //KLONDIKE_GAMEACTIONCONTROLLER_H
