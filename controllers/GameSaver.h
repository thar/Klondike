
#ifndef KLONDIKE_UNDOLISTSAVER_H
#define KLONDIKE_UNDOLISTSAVER_H

#include "../models/KlondikeCommand.h"
#include "../models/Game.h"
namespace controllers
{
    class GameSaver
    {
    public:
        virtual void addRandomSeed(unsigned int seed) = 0;
        virtual void addDeckPath(std::string deckPath) = 0;
        virtual void addCommand(KlondikeCommand& command) = 0;
        virtual unsigned int getRandomSeed() = 0;
        virtual std::string getDeckPath() = 0;
        virtual void restoreCommands(Game& game) = 0;

    };
}


#endif //KLONDIKE_UNDOLISTSAVER_H
