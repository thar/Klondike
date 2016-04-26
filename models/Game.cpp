#include "Game.h"
#include "KlondikeCommandShopBuilder.h"

Game::Game(GameDeck gameDeck)
        : gameBoard_(gameDeck.getSuitsNames(), gameDeck.getPile()), score_(0),
          gameCommandShop_(KlondikeCommandShopBuilder::createCommandShop(gameBoard_, score_))
{
}

std::shared_ptr<KlondikeCommand> Game::getCommand(unsigned int index)
{
    return gameCommandShop_.getCommand(index);
}

std::ostream& operator<<(std::ostream& os, const Game& obj)
{
    os << obj.gameBoard_;
    return os;
}