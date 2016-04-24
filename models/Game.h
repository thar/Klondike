#ifndef KLONDIKE_GAME_H
#define KLONDIKE_GAME_H


#include "Waist.h"
#include "Stock.h"
#include "Foundation.h"
#include "Tableau.h"

class Game
{
public:
    Game(GameDeck gameDeck);
protected:
private:
    GameDeck gameDeck_;
    Pile gamePile_;
    Foundation foundation_;
    Tableau tableau_;
    Stock stock_;
    Waist waist_;

    friend std::ostream& operator<<(std::ostream& os, const Game& obj);

};


#endif //KLONDIKE_GAME_H
