#include "LocalLogic.h"
#include "LocalScoreController.h"
#include "UserActionListController.h"
#include "StartGameControllerBuilder.h"
#include "ExitControllerBuilder.h"
#include "LoadGameControllerBuilder.h"


controllers::local::LocalLogic::LocalLogic() : gameState_(PLAYER_NOT_SELECTED), playerType_(UNINITIALIZED), deckController_(nullptr), gameActionsController_(nullptr),
               loadGameController_(nullptr), startGameController_(nullptr), abandonController_(nullptr),
               exitController_(nullptr), game_(nullptr), randomSeed_(0), deckPath_(""), abruptExit_(false)
{
    playerChooseController_ = PlayerChooseControllerBuilder(*this).getPlayerChooseController();
    exitController_ = ExitControllerBuilder(*this).getExitController();
    startGameController_ = StartGameControllerBuilder(*this).getStartGameController();
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
                return startGameController_;
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
            case GAME_ABANDONED:
                gameState_ = GAME_FINISHED;
                return std::make_shared<controllers::local::LocalScoreController>(game_);
            case GAME_FINISHED:
                return exitController_;
        }
    }
}

void controllers::local::LocalLogic::setPlayer(PlayerType playerType)
{
    playerType_ = playerType;
    deckController_ = DeckControllerBuilder(*this, playerType_).getDeckController();
    gameState_ = playerType == USER ? GAME_NOT_STARTED : GAME_NEW;
}
void controllers::local::LocalLogic::setDeck(std::string deckPath)
{
    deckPath_ = deckPath;
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
    abruptExit_ = false;
    gameState_ = GAME_ABANDONED;
}

void controllers::local::LocalLogic::setRandomNumberGeneratorSeed(unsigned int seed)
{
    randomSeed_ = seed;
    std::srand(randomSeed_);
}

void controllers::local::LocalLogic::newGame()
{
    gameState_ = GAME_NEW;
}

void controllers::local::LocalLogic::loadGame()
{
    gameState_ = GAME_LOAD;
    loadGameController_ = LoadGameControllerBuilder(*this).getLoadController();
}

void controllers::local::LocalLogic::save(controllers::GameSaver &gameSaver)
{
    gameSaver.addDeckPath(deckPath_);
    gameSaver.addRandomSeed(randomSeed_);
}

void controllers::local::LocalLogic::restore(controllers::GameSaver &gameSaver)
{
    setRandomNumberGeneratorSeed(gameSaver.getRandomSeed());
    setDeck(gameSaver.getDeckPath());
    gameSaver.restoreCommands(*game_);
    //restore each command
}
