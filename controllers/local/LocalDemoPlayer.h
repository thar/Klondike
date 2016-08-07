#ifndef KLONDIKE_LOCALDEMOPLAYER_H
#define KLONDIKE_LOCALDEMOPLAYER_H


#include "../PlayerController.h"

class LocalDemoPlayer : public PlayerController
{
public:
    bool isGameFinished()
    {
        return true;
    }
    std::shared_ptr<controllers::OperationController> getOperationController()
    {
        return nullptr;
    }
protected:
private:
};


#endif //KLONDIKE_LOCALDEMOPLAYER_H
