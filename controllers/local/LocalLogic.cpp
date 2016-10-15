#include "LocalLogic.h"
#include "LocalScoreController.h"
#include "ExitGameAction.h"
#include "GiveUpGameAction.h"
#include "UserActionListController.h"


controllers::local::LocalLogic::LocalLogic() : gameState_(PLAYER_NOT_SELECTED), playerType_(UNINITIALIZED), deckController_(nullptr), gameActionsController_(nullptr),
               loadGameController_(nullptr), startGameController_(nullptr), abandonController_(nullptr),
               exitController_(nullptr), game_(nullptr), abruptExit_(false)
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
    else
    {
        switch (gameState_)
        {
            case PLAYER_NOT_SELECTED:
                return playerChooseController_;
            case GAME_NOT_STARTED:
                return nullptr; //loadOrNew
            case GAME_NEW:
                return deckController_;
            case GAME_LOAD:
                return loadGameController_;
            case GAME_STARTED:
                if(!game_->isFinished())
                    return gameActionsController_;
                else
                {
                    gameState_ = GAME_FINISHED;
                    return std::make_shared<controllers::local::LocalScoreController>(game_);
                }
            case GAME_FINISHED:
                return exitController_;
        }
    }
}

void controllers::local::LocalLogic::setPlayer(PlayerType playerType)
{
    playerType_ = playerType;
    deckController_ = DeckControllerBuilder(*this, playerType_).getDeckController();
    gameState_ = playerType == USER ? GAME_NEW : GAME_NEW;
    //loadGameController_ = LoadGameControllerBuilder(*playerController_, *this).getGameControllerBuilder():
}
void controllers::local::LocalLogic::setDeck(std::string deckPath)
{
    game_ = std::make_shared<Game>(GameDeck(deckPath));
    gameActionsController_ = GameActionsControllerBuilder(*game_, *this).getGameActionsController(playerType_);
    gameState_ = GAME_STARTED;
}
void controllers::local::LocalLogic::exitGame()
{
    playerType_ = UNINITIALIZED;
    game_.reset();
    abruptExit_ = true;
    gameState_ = PLAYER_NOT_SELECTED;
}
void controllers::local::LocalLogic::abandonGame()
{
    playerType_ = UNINITIALIZED;
    game_.reset();
    abruptExit_ = false;
    gameState_ = PLAYER_NOT_SELECTED;
}

void controllers::local::LocalLogic::setRandomNumberGeneratorSeed(unsigned int seed)
{
    randomSeed_ = seed;
    std::srand(randomSeed_);
}