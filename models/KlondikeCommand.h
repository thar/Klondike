#ifndef KLONDIKE_KLONDIKECOMMAND_H
#define KLONDIKE_KLONDIKECOMMAND_H

#include "PilesGroup.h"

class KlondikeCommand
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    bool validate()
    {
        valid_ = false;
        __validate();
        return valid_;
    };

protected:
    KlondikeCommand(PilesGroup& origin, PilesGroup& destiny)
            : valid_(false), origin_(origin), destiny_(destiny), cardsToMove_(0)
    {}
    virtual void __validate() = 0;
    bool valid_;
    PilesGroup& origin_;
    PilesGroup& destiny_;
    unsigned int cardsToMove_;
};


#endif //KLONDIKE_KLONDIKECOMMAND_H
