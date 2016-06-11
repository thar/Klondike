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

    void setOriginPile(std::string originPile)
    { originPile_ = originPile; }

    void setDestinyPile(std::string destinyPile)
    { destinyPile_ = destinyPile; }

    void setCardsToMove(unsigned int cardsToMove)
    { cardsToMove_ = cardsToMove; }

protected:
    KlondikeCommand(int &score, int movementScore)
            : valid_(false), score_(score), cardsToMove_(0),
              movementScore_(movementScore)
    {}
    virtual void __validate() = 0;

    bool valid_;
    int& score_;
    unsigned int cardsToMove_;
    const int movementScore_;
    std::string originPile_;
    std::string destinyPile_;
};


#endif //KLONDIKE_KLONDIKECOMMAND_H
