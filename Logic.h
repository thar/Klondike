#ifndef KLONDIKE_LOGIC_H
#define KLONDIKE_LOGIC_H


#include <memory>
#include "controllers/OperationController.h"

class Logic
{

public:
    virtual std::shared_ptr<controllers::OperationController> getOperationController() = 0;

protected:
private:
};


#endif //KLONDIKE_LOGIC_H
