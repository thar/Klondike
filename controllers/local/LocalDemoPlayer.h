#ifndef KLONDIKE_LOCALDEMOPLAYER_H
#define KLONDIKE_LOCALDEMOPLAYER_H


#include "LocalPlayerController.h"

class LocalDemoPlayer : public LocalPlayerController
{
public:
    LocalDemoPlayer(std::shared_ptr<Game> &game) : LocalPlayerController(game)
    { state_ = State::GAME_FINISHED; }
    std::shared_ptr<controllers::OperationController> getOperationController()
    {
        return nullptr;
    }
    void getOriginPile() {}
    void getDestinyPile() {}
protected:
private:
};


#endif //KLONDIKE_LOCALDEMOPLAYER_H
