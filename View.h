#ifndef KLONDIKE_VIEW_H
#define KLONDIKE_VIEW_H


#include "controllers/OperationControllerVisitor.h"
#include "controllers/OperationController.h"

class View : public controllers::OperationControllerVisitor
{
public:
    virtual void interact(controllers::OperationController& operationController) = 0;

protected:
private:
};


#endif //KLONDIKE_VIEW_H
