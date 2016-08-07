#ifndef KLONDIKE_OPERATIONCONTROLLER_H
#define KLONDIKE_OPERATIONCONTROLLER_H


#include "OperationControllerVisitor.h"

namespace controllers
{

    class OperationController
    {

    public:
        virtual void accept(OperationControllerVisitor& operationControllerVisitor) = 0;

    };
}

#endif //KLONDIKE_OPERATIONCONTROLLER_H
