
#ifndef KLONDIKE_UNDOLISTSAVER_H
#define KLONDIKE_UNDOLISTSAVER_H

#include "../models/KlondikeCommand.h"
namespace controllers
{
    class UndoListSaver
    {
    public:
        virtual void addCommand(KlondikeCommand& command) = 0;
    };
}


#endif //KLONDIKE_UNDOLISTSAVER_H
