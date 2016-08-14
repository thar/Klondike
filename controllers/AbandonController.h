#ifndef KLONDIKE_ABANDONCONTROLLER_H
#define KLONDIKE_ABANDONCONTROLLER_H

#include "OperationController.h"

namespace controllers
{
    class AbandonController : public OperationController
    {
    public:
        virtual void abandonGame();
    protected:
    private:
    };
}

#endif //KLONDIKE_ABANDONCONTROLLER_H
