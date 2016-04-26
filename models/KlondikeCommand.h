#ifndef KLONDIKE_KLONDIKECOMMAND_H
#define KLONDIKE_KLONDIKECOMMAND_H

#include "PilesGroup.h"
#include <memory>

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
    virtual std::shared_ptr<KlondikeCommand> clone() = 0;

protected:
    KlondikeCommand(PilesGroup& origin, PilesGroup& destiny, int& score, int movementScore)
            : valid_(false), origin_(origin), destiny_(destiny), score_(score), cardsToMove_(0),
              movementScore_(movementScore)
    {}
    virtual void __validate() = 0;

    bool valid_;
    PilesGroup& origin_;
    PilesGroup& destiny_;
    int& score_;
    unsigned int cardsToMove_;
    const int movementScore_;
};


#endif //KLONDIKE_KLONDIKECOMMAND_H
