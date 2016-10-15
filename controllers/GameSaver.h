
#ifndef KLONDIKE_UNDOLISTSAVER_H
#define KLONDIKE_UNDOLISTSAVER_H

#include "../models/KlondikeCommand.h"
namespace controllers
{
    class GameSaver
    {
    public:
        virtual void addRandomSeed(unsigned int seed) = 0;
        virtual void addDeckPath(std::string deckPath) = 0;
        virtual void addCommand(KlondikeCommand& command) = 0;
    };
}


#endif //KLONDIKE_UNDOLISTSAVER_H
