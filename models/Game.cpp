#include <iostream>
#include "Game.h"

Game::Game(GameDeck gameDeck)
        : gameDeck_(gameDeck), gamePile_(gameDeck_.getPile()),
          foundation_(gameDeck_.getNumberOfSuits()), tableau_(gamePile_), stock_(gamePile_)
{
}

std::ostream& operator<<(std::ostream& os, const Game& obj)
{
    os << "STOCK" << std::endl << obj.stock_ << std::endl;
    os << "WAIST" << std::endl << obj.waist_ << std::endl;
    os << "FOUNDATION" << std::endl << obj.foundation_ << std::endl;
    os << "TABLEAU" << std::endl << obj.tableau_;
    return os;
}