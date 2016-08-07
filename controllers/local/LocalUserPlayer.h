#ifndef KLONDIKE_LOCALUSERPLAYER_H
#define KLONDIKE_LOCALUSERPLAYER_H


#include "../Player.h"

class LocalUserPlayer : public Player
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


#endif //KLONDIKE_LOCALUSERPLAYER_H
