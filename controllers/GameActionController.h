#ifndef KLONDIKE_GAMEACTIONCONTROLLER_H
#define KLONDIKE_GAMEACTIONCONTROLLER_H

#include "OperationController.h"

namespace controllers
{
    class GameActionController : public OperationController
    {
    public:
        virtual void giveUpGame() = 0;
        virtual void undoMovement() = 0;
        virtual void redoMovement() = 0;
        virtual void saveGame() = 0;
    };
}


#endif //KLONDIKE_GAMEACTIONCONTROLLER_H
