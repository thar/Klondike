#ifndef KLONDIKE_LOCALUSERPLAYER_H
#define KLONDIKE_LOCALUSERPLAYER_H

#include "../NewOrLoadController.h"
#include "../ChooseDeckController.h"
#include "LocalPlayerController.h"
#include "../GameActionController.h"
#include "../../models/FoundationToTableauCommand.h"
#include "../../models/StockToWaistCommand.h"
#include "../../models/TableauToFoundationCommand.h"
#include "../../models/TableauToTableauCommand.h"
#include "../../models/WaistToFoundationCommand.h"
#include "../../models/WaistToStockCommand.h"
#include "../../models/WaistToTableauCommand.h"

class LocalUserPlayer : public LocalPlayerController
{
public:
    LocalUserPlayer(std::shared_ptr<Game> &game) : LocalPlayerController(game)
    { state_ = State::NEW_GAME; }
    std::shared_ptr<controllers::OperationController> getOperationController()
    {
        switch (state_)
        {
            case State::NEW_GAME:
                return nullptr;
                //return std::make_shared<controllers::NewOrLoadController>(*this);
            case State::LOAD_GAME:
                return nullptr;
            case State::IN_GAME:
                if (!game_)
                    return nullptr;
                    //return std::make_shared<controllers::ChooseDeckController>(*this);
                else
                    return nullptr;
                    //return std::make_shared<controllers::GameActionController>(*this, *game_);
            case State::SAVE:
                return nullptr;
            case State::GAME_FINISHED:
                return nullptr;
        }
    }
    void getOriginPile() {}
    void getDestinyPile() {}
protected:
private:
};


#endif //KLONDIKE_LOCALUSERPLAYER_H
