#ifndef KLONDIKE_GAMECONTROLLER_H
#define KLONDIKE_GAMECONTROLLER_H

#include <memory>
#include <string>
#include "PlayerType.h"
#include "GameSaver.h"

namespace controllers
{
    class GameController
    {
    public:
        virtual void setPlayer(PlayerType player) = 0;
        virtual void newGame() = 0;
        virtual void loadGame() = 0;
        virtual void setDeck(std::string deckPath) = 0;
        virtual void exitGame() = 0;
        virtual void abandonGame() = 0;
        virtual void restart() = 0;
        virtual void setRandomNumberGeneratorSeed(unsigned int seed) = 0;
        virtual void save(GameSaver& gameSaver) = 0;
        virtual void restore(GameSaver& gameSaver) = 0;
    protected:
    private:
    };
}


#endif //KLONDIKE_GAMECONTROLLER_H
