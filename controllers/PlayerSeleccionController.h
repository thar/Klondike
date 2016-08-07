#ifndef KLONDIKE_PLAYERSELECCIONCONTROLLER_H
#define KLONDIKE_PLAYERSELECCIONCONTROLLER_H

#include "OperationController.h"

namespace controllers
{
    enum class PlayerType
    {
        USER, DEMO
    };

    class PlayerSeleccionController : public OperationController
    {
    public:
        virtual void selectPlayer(PlayerType player) = 0;
    };
}


#endif //KLONDIKE_PLAYERSELECCIONCONTROLLER_H
