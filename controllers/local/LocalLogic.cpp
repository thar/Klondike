#include "LocalLogic.h"
#include "LocalScoreController.h"
#include "ExitGameAction.h"
#include "GiveUpGameAction.h"
#include "UserActionListController.h"


controllers::local::LocalLogic::LocalLogic() : playerType_(UNINITIALIZED), deckController_(nullptr), gameActionsController_(nullptr),
               loadGameController_(nullptr), abandonController_(nullptr), exitController_(nullptr), scoreController_(nullptr),
               game_(nullptr), abruptExit_(false)
{
    playerChooseController_ = PlayerChooseControllerBuilder(*this).getPlayerChooseController();
    exitController_ = std::make_shared<controllers::local::UserActionListController>();
    exitController_->addAction(std::make_shared<GiveUpGameAction>(*this));
    exitController_->addAction(std::make_shared<ExitGameAction>(*this));
};

std::shared_ptr<controllers::OperationController> controllers::local::LocalLogic::getOperationController()
{
    if(abruptExit_)
        return nullptr;
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
    else if (!scoreController_)
    {
        scoreController_ = std::make_shared<controllers::local::LocalScoreController>(game_);
        return scoreController_;
    }
    else
    {
        scoreController_ = nullptr;
        return exitController_;
    }
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

void controllers::local::LocalLogic::setRandomNumberGeneratorSeed(unsigned int seed)
{
    randomSeed_ = seed;
    std::srand(randomSeed_);
}