#ifndef KLONDIKE_LOCALUSERPLAYER_H
#define KLONDIKE_LOCALUSERPLAYER_H

#include "../NewGameController.h"
#include "../ChooseDeckController.h"
#include "LocalPlayerController.h"

class LocalUserPlayer : public LocalPlayerController
{
public:
    LocalUserPlayer() { state_ = State::NEW_GAME; }
    std::shared_ptr<controllers::OperationController> getOperationController()
    {
        switch (state_)
        {
            case State::NEW_GAME:
                return std::make_shared<controllers::NewGameController>(*this);
            case State::LOAD_GAME:
                return nullptr;
            case State::IN_GAME:
                if (!game_)
                    return std::make_shared<controllers::ChooseDeckController>(*this);
                else
                    return nullptr;
            case State::GIVE_UP:
                return nullptr;
            case State::SAVE:
                return nullptr;
            case State::GAME_FINISHED:
                return nullptr;
        }
    }
protected:
private:
};


#endif //KLONDIKE_LOCALUSERPLAYER_H
