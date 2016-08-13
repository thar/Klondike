#ifndef KLONDIKE_PLAYER_H
#define KLONDIKE_PLAYER_H


#include "PlayerControllerVisitor.h"
namespace controllers
{
    class PlayerController
    {
    public:
        virtual void accept(PlayerControllerVisitor &playerControllerVisitor) = 0;

    protected:
    private:
    };
}


#endif //KLONDIKE_PLAYER_H
