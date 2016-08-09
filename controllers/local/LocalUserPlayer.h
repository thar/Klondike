#ifndef KLONDIKE_LOCALUSERPLAYER_H
#define KLONDIKE_LOCALUSERPLAYER_H

#include "../NewGameController.h"
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
                    return std::make_shared<controllers::GameActionController>(*this, *game_);
            case State::SAVE:
                return nullptr;
            case State::GAME_FINISHED:
                return nullptr;
        }
    }
    void getOriginPile() {}
    void getDestinyPile() {}
    void visit(FoundationToTableauCommand& command) {}
    void visit(StockToWaistCommand& command)
    {
    }
    void visit(TableauToFoundationCommand& command)
    {
    }
    void visit(TableauToTableauCommand& command)
    {
    }
    void visit(WaistToFoundationCommand& command)
    {
    }
    void visit(WaistToStockCommand& command)
    {
    }
    void visit(WaistToTableauCommand& command)
    {
    }
protected:
private:
};


#endif //KLONDIKE_LOCALUSERPLAYER_H
