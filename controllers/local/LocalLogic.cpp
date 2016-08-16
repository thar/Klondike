#include "LocalLogic.h"


controllers::local::LocalLogic::LocalLogic() : playerType_(UNINITIALIZED), deckController_(nullptr), gameActionsController_(nullptr),
               loadGameController_(nullptr), abandonController_(nullptr), exitController_(nullptr),
               game_(nullptr), abruptExit_(false)
{
    playerChooseController_ = PlayerChooseControllerBuilder(*this).getPlayerChooseController();
};

std::shared_ptr<controllers::OperationController> controllers::local::LocalLogic::getOperationController()
{
    if(abruptExit_)
        return exitController_;
    else if(UNINITIALIZED == playerType_)
        return playerChooseController_;
    else if(!game_)
    {
        if (!loadGameController_)
            return deckController_;
        else
            return loadGameController_;
    }
    else if(!game_->isFinished())
        return gameActionsController_;
    else
        return abandonController_;
}

void controllers::local::LocalLogic::setPlayer(PlayerType playerType)
{
    playerType_ = playerType;
    deckController_ = DeckControllerBuilder(*this, playerType_).getDeckController();
    //loadGameController_ = LoadGameControllerBuilder(*playerController_, *this).getGameControllerBuilder():
}
void controllers::local::LocalLogic::setDeck(std::string deckPath)
{
    game_ = std::make_shared<Game>(GameDeck(deckPath));
    gameActionsController_ = GameActionsControllerBuilder(*game_, *this).getGameActionsController(playerType_);
}
void controllers::local::LocalLogic::exitGame()
{
    playerType_ = UNINITIALIZED;
    game_.reset();
    abruptExit_ = true;
}
void controllers::local::LocalLogic::abandonGame()
{
    playerType_ = UNINITIALIZED;
    game_.reset();
    abruptExit_ = false;
}