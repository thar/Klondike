#ifndef KLONDIKE_EXITGAMECONTROLLER_H
#define KLONDIKE_EXITGAMECONTROLLER_H

#include "OperationController.h"

namespace controllers
{
    class ExitGameController : public OperationController
    {
    public:
        virtual void setContinueGame() = 0;
        virtual void setExitGame() = 0;
    };
}


#endif //KLONDIKE_EXITGAMECONTROLLER_H
