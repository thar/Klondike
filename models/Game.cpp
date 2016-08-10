#include "Game.h"
#include "KlondikeCommandShopBuilder.h"

Game::Game(GameDeck gameDeck)
        : gameBoard_(gameDeck.getSuitsNames(), gameDeck.getPile()), score_(0),
          gameCommandShop_(KlondikeCommandShopBuilder::createCommandShop(gameBoard_, score_))
{
}

std::shared_ptr<KlondikeCommand> Game::getCommand(unsigned int index)
{
    assert(index < gameCommandShop_.size());
    return gameCommandShop_.getCommand(index);
}

bool Game::isFinished()
{
    //TODO
    return givedUp_ || false;
}

void Game::giveUp()
{
    givedUp_ = true;
}

std::ostream& operator<<(std::ostream& os, const Game& obj)
{
    os << obj.gameBoard_;
    return os;
}