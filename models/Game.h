#ifndef KLONDIKE_GAME_H
#define KLONDIKE_GAME_H

#include "GameBoard.h"
#include "KlondikeCommandShop.h"

class Game
{
public:
    Game(GameDeck gameDeck);
    std::shared_ptr<KlondikeCommand> getCommand(unsigned int index);
    bool isFinished();
    void giveUp();
protected:
private:
    GameBoard gameBoard_;
    int score_;
    KlondikeCommandShop gameCommandShop_;
    bool givedUp_;

    friend std::ostream& operator<<(std::ostream& os, const Game& obj);

};


#endif //KLONDIKE_GAME_H
