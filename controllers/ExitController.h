#ifndef KLONDIKE_EXITCONTROLLER_H
#define KLONDIKE_EXITCONTROLLER_H

#include "OperationController.h"

namespace controllers
{
    class ExitController : public OperationController
    {
    public:
        virtual void exitGame() = 0;
    protected:
    private:
    };
}

#endif //KLONDIKE_EXITCONTROLLER_H
