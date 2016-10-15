#include "LocalLogic.h"
#include "LocalScoreController.h"
#include "UserActionListController.h"
#include "StartGameControllerBuilder.h"
#include "ExitControllerBuilder.h"
#include "LoadGameControllerBuilder.h"

#include <signal.h>

controllers::local::LocalLogic* controllers::local::LocalLogic::instance = nullptr;

controllers::local::LocalLogic::LocalLogic() : gameState_(PLAYER_NOT_SELECTED), playerType_(UNINITIALIZED),
               game_(nullptr), randomSeed_(0), deckPath_("")
{
    registerSignalHandler();
};

std::shared_ptr<controllers::OperationController> controllers::local::LocalLogic::getOperationController()
{
    switch (gameState_)
    {
        case PLAYER_NOT_SELECTED:
            return PlayerChooseControllerBuilder(*this).getPlayerChooseController();
        case GAME_NOT_STARTED:
            return StartGameControllerBuilder(*this).getStartGameController();
        case GAME_NEW:
            return DeckControllerBuilder(*this, playerType_).getDeckController();
        case GAME_LOAD:
            return LoadGameControllerBuilder(*this).getLoadController();
        case GAME_STARTED:
            if(!game_->isFinished())
                return GameActionsControllerBuilder(*game_, *this).getGameActionsController(playerType_);
        case GAME_ABANDONED:
            gameState_ = GAME_FINISHED;
            return std::make_shared<controllers::local::LocalScoreController>(game_);
        case GAME_FINISHED:
            return ExitControllerBuilder(*this).getExitController();
        case ABRUPT_EXIT:
            return nullptr;
    }
}

void controllers::local::LocalLogic::setPlayer(PlayerType playerType)
{
    playerType_ = playerType;
    gameState_ = playerType == USER ? GAME_NOT_STARTED : GAME_NEW;
}
void controllers::local::LocalLogic::setDeck(std::string deckPath)
{
    deckPath_ = deckPath;
    game_ = std::make_shared<Game>(GameDeck(deckPath));
    gameState_ = GAME_STARTED;
}
void controllers::local::LocalLogic::exitGame()
{
    playerType_ = UNINITIALIZED;
    game_.reset();
    gameState_ = ABRUPT_EXIT;
}
void controllers::local::LocalLogic::abandonGame()
{
    playerType_ = UNINITIALIZED;
    gameState_ = GAME_ABANDONED;
}

void controllers::local::LocalLogic::restart()
{
    playerType_ = UNINITIALIZED;
    game_.reset();
    gameState_ = PLAYER_NOT_SELECTED;
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
}

void controllers::local::LocalLogic::registerSignalHandler()
{
    controllers::local::LocalLogic::instance = this;
    struct sigaction sigIntHandler;

    sigIntHandler.sa_handler = controllers::local::LocalLogic::signalHandler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;

    sigaction(SIGINT, &sigIntHandler, NULL);
}
