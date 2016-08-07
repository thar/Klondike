#ifndef KLONDIKE_PLAYER_H
#define KLONDIKE_PLAYER_H


#include "OperationController.h"
#include "../models/GameDeck.h"
#include "../models/Game.h"
#include "State.h"
#include <memory>

class PlayerController
{
public:
    //TODO: All the functions to interact with the game
    virtual bool isGameFinished() = 0;
    virtual std::shared_ptr<controllers::OperationController> getOperationController() = 0;
    void setLoadGame() { state_ = State::LOAD_GAME; }
    void setNewGame() { state_ = State::IN_GAME; }
    void setDeck(const std::string deckName)
    {
        gameDeck_ = std::make_shared<GameDeck>(deckName);
        game_ = std::make_shared<Game>(*gameDeck_);

        state_ = State::GAME_FINISHED;
    }
protected:
    std::shared_ptr<GameDeck> gameDeck_;
    std::shared_ptr<Game> game_;
    State state_;
private:
};


#endif //KLONDIKE_PLAYER_H
